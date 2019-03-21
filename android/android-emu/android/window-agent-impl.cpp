// Copyright 2015-2017 The Android Open Source Project
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

#include "android/emulation/control/window_agent.h"

#include "android/emulator-window.h"
#include "android/skin/event.h"
#include "android/skin/qt/emulator-container.h"
#include "android/skin/qt/emulator-qt-window.h"
#include "android/utils/debug.h"

static_assert(WINDOW_MESSAGE_GENERIC == int(Ui::OverlayMessageType::None),
              "Bad message type enum value (None)");
static_assert(WINDOW_MESSAGE_INFO == int(Ui::OverlayMessageType::Info),
              "Bad message type enum value (Info)");
static_assert(WINDOW_MESSAGE_WARNING == int(Ui::OverlayMessageType::Warning),
              "Bad message type enum value (Warning)");
static_assert(WINDOW_MESSAGE_ERROR == int(Ui::OverlayMessageType::Error),
              "Bad message type enum value (Error)");
static_assert(WINDOW_MESSAGE_OK == int(Ui::OverlayMessageType::Ok),
              "Bad message type enum value (Ok)");

static const QAndroidEmulatorWindowAgent sQAndroidEmulatorWindowAgent = {
        .getEmulatorWindow = emulator_window_get,
        .rotate90Clockwise =
                [] {
                    return emulator_window_rotate_90(true);
                },
        .rotate = emulator_window_rotate,
        .getRotation =
                [] {
                    EmulatorWindow* window = emulator_window_get();
                    if (!window) return SKIN_ROTATION_0;
                    SkinLayout* layout = emulator_window_get_layout(window);
                    if (!layout) return SKIN_ROTATION_0;
                    return layout->orientation;
                },
        .showMessage =
                [](const char* message, WindowMessageType type, int timeoutMs) {
                    if (const auto win = EmulatorQtWindow::getInstance()) {
                        win->showMessage(
                                QString::fromUtf8(message),
                                static_cast<Ui::OverlayMessageType>(type),
                                timeoutMs);
                    } else {
                        const auto printer =
                                (type == WINDOW_MESSAGE_ERROR)
                                        ? &derror
                                        : (type == WINDOW_MESSAGE_WARNING)
                                                  ? &dwarning
                                                  : &dprint;
                        printer("%s", message);
                    }
                },
        .showMessageWithDismissCallback =
                [](const char* message, WindowMessageType type,
                   const char* dismissText, void* context,
                   void (*func)(void*), int timeoutMs) {
                    if (const auto win = EmulatorQtWindow::getInstance()) {
                        win->showMessageWithDismissCallback(
                                QString::fromUtf8(message),
                                static_cast<Ui::OverlayMessageType>(type),
                                QString::fromUtf8(dismissText),
                                [func, context] { if (func) func(context); },
                                timeoutMs);
                    } else {
                        const auto printer =
                                (type == WINDOW_MESSAGE_ERROR)
                                        ? &derror
                                        : (type == WINDOW_MESSAGE_WARNING)
                                                  ? &dwarning
                                                  : &dprint;
                        printer("%s", message);
                        // Don't necessarily perform the func since the
                        // user doesn't get a chance to dismiss.
                    }
                },
        .fold =
              [](bool is_fold) {
                  if (const auto win = EmulatorQtWindow::getInstance()) {
                      QtUICommand cmd = is_fold ? QtUICommand::FOLD : QtUICommand::UNFOLD;
                      win->runOnUiThread([win, cmd]() {
                          win->toolWindow()->handleUICommand(cmd);
                      });
                  }
              },
        .isFolded =
                [] {
                    if (const auto win = EmulatorQtWindow::getInstance()) {
                        return win->isFolded();
                    }
                    return false;
                },

        .setUIDisplayRegion =
                [](int x_offset, int y_offset, int w, int h) {
                        SkinEvent* event = new SkinEvent();
                        event->type = kEventSetDisplayRegionAndUpdate;
                        event->u.display_region.xOffset = x_offset;
                        event->u.display_region.yOffset = y_offset;
                        event->u.display_region.width   = w;
                        event->u.display_region.height  = h;
                        skin_event_add(event);
                },
        .setMultiDisplay =
                [](int id, int x, int y, int w, int h, bool add) {
                    SkinEvent* event = new SkinEvent();
                    event->type = kEventSetMultiDisplay;
                    event->u.multi_display.id = id;
                    event->u.multi_display.xOffset = x;
                    event->u.multi_display.yOffset = y;
                    event->u.multi_display.width = w;
                    event->u.multi_display.height = h;
                    event->u.multi_display.add= add;
                    skin_event_add(event);
                },
};

const QAndroidEmulatorWindowAgent* const gQAndroidEmulatorWindowAgent =
        &sQAndroidEmulatorWindowAgent;
