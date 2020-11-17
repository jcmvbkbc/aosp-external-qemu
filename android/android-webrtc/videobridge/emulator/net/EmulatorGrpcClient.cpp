// Copyright (C) 2020 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include <grpcpp/grpcpp.h>                                    // for ClientC...
#include <rtc_base/logging.h>                                 // for RTC_LOG
#include <map>                                                // for multimap
#include <memory>                                             // for shared_ptr
#include <string>                                             // for operator+
#include <utility>                                            // for __unwra...

#include "android/base/StringView.h"                          // for StringView
#include "android/base/files/IniFile.h"                       // for IniFile
#include "android/emulation/control/secure/BasicTokenAuth.h"  // for BasicTo...
#include "emulator/net/EmulatorGrcpClient.h"                  // for Emulato...
#include "emulator_controller.grpc.pb.h"                      // for Emulato...
#include "grpc/grpc_security_constants.h"                     // for LOCAL_TCP
#include "grpc/impl/codegen/connectivity_state.h"             // for (anonym...
#include "grpcpp/channel_impl.h"                              // for Channel
#include "grpcpp/security/credentials.h"                      // for LocalCr...

namespace emulator {
namespace webrtc {

// A plugin that inserts the basic auth headers into a gRPC request
// if needed.
class BasicTokenAuthenticator : public grpc::MetadataCredentialsPlugin {
public:
    BasicTokenAuthenticator(const grpc::string& token)
        : mToken("Bearer " + token) {}
    ~BasicTokenAuthenticator() = default;

    grpc::Status GetMetadata(
            grpc::string_ref service_url,
            grpc::string_ref method_name,
            const grpc::AuthContext& channel_auth_context,
            std::multimap<grpc::string, grpc::string>* metadata) override {
        metadata->insert(std::make_pair(
                android::emulation::control::BasicTokenAuth::DEFAULT_HEADER,
                mToken));
        return grpc::Status::OK;
    }

private:
    grpc::string mToken;
};

bool EmulatorGrpcClient::hasOpenChannel() {
    if (!mChannel) {
        initializeChannel();
    }
    if (!mChannel)
        return false;

    auto state = mChannel->GetState(true);
    RTC_LOG(INFO) << "Channel state: " << state;
    return state == GRPC_CHANNEL_READY || state == GRPC_CHANNEL_IDLE;
}

std::unique_ptr<android::emulation::control::EmulatorController::Stub>
EmulatorGrpcClient::stub() {
    if (!mChannel) {
        initializeChannel();
    }

    return android::emulation::control::EmulatorController::NewStub(mChannel);
}

std::unique_ptr<grpc::ClientContext> EmulatorGrpcClient::newContext() {
    auto ctx = std::make_unique<grpc::ClientContext>();
    if (mCredentials) {
        ctx->set_credentials(mCredentials);
    }
    return ctx;
}

bool EmulatorGrpcClient::initializeChannel() {
    android::base::IniFile iniFile(mDiscoveryFile);
    iniFile.read();
    if (!iniFile.hasKey("grpc.port") || iniFile.hasKey("grpc.server_cert")) {
        RTC_LOG(LERROR) << "No grpc port, or tls enabled. gRPC disabled.";
        return false;
    }
    std::string grpc_address =
            "localhost:" + iniFile.getString("grpc.port", "8554");
    mChannel = grpc::CreateChannel(
            grpc_address, ::grpc::experimental::LocalCredentials(LOCAL_TCP));

    // Install token authenticator if needed.
    if (iniFile.hasKey("grpc.token")) {
        auto token = iniFile.getString("grpc.token", "");
        mCredentials = grpc::MetadataCredentialsFromPlugin(
                std::make_unique<BasicTokenAuthenticator>(token));
    }

    RTC_LOG(INFO) << "Initialized grpc Stub.";
    return true;
}
}  // namespace webrtc
}  // namespace emulator
