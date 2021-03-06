/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_CHARDEV_GENERATED_TRACERS_H
#define TRACE_CHARDEV_GENERATED_TRACERS_H

#include "qemu-common.h"
#include "trace/control.h"

extern TraceEvent _TRACE_WCT_INIT_EVENT;
extern TraceEvent _TRACE_WCT_CMD_RE_EVENT;
extern TraceEvent _TRACE_WCT_CMD_ST_EVENT;
extern TraceEvent _TRACE_WCT_CMD_SP_EVENT;
extern TraceEvent _TRACE_WCT_CMD_TS_EVENT;
extern TraceEvent _TRACE_WCT_CMD_OTHER_EVENT;
extern TraceEvent _TRACE_WCT_SPEED_EVENT;
extern TraceEvent _TRACE_SPICE_VMC_WRITE_EVENT;
extern TraceEvent _TRACE_SPICE_VMC_READ_EVENT;
extern TraceEvent _TRACE_SPICE_VMC_REGISTER_INTERFACE_EVENT;
extern TraceEvent _TRACE_SPICE_VMC_UNREGISTER_INTERFACE_EVENT;
extern TraceEvent _TRACE_SPICE_VMC_EVENT_EVENT;
extern uint16_t _TRACE_WCT_INIT_DSTATE;
extern uint16_t _TRACE_WCT_CMD_RE_DSTATE;
extern uint16_t _TRACE_WCT_CMD_ST_DSTATE;
extern uint16_t _TRACE_WCT_CMD_SP_DSTATE;
extern uint16_t _TRACE_WCT_CMD_TS_DSTATE;
extern uint16_t _TRACE_WCT_CMD_OTHER_DSTATE;
extern uint16_t _TRACE_WCT_SPEED_DSTATE;
extern uint16_t _TRACE_SPICE_VMC_WRITE_DSTATE;
extern uint16_t _TRACE_SPICE_VMC_READ_DSTATE;
extern uint16_t _TRACE_SPICE_VMC_REGISTER_INTERFACE_DSTATE;
extern uint16_t _TRACE_SPICE_VMC_UNREGISTER_INTERFACE_DSTATE;
extern uint16_t _TRACE_SPICE_VMC_EVENT_DSTATE;
#define TRACE_WCT_INIT_ENABLED 1
#define TRACE_WCT_CMD_RE_ENABLED 1
#define TRACE_WCT_CMD_ST_ENABLED 1
#define TRACE_WCT_CMD_SP_ENABLED 1
#define TRACE_WCT_CMD_TS_ENABLED 1
#define TRACE_WCT_CMD_OTHER_ENABLED 1
#define TRACE_WCT_SPEED_ENABLED 1
#define TRACE_SPICE_VMC_WRITE_ENABLED 1
#define TRACE_SPICE_VMC_READ_ENABLED 1
#define TRACE_SPICE_VMC_REGISTER_INTERFACE_ENABLED 1
#define TRACE_SPICE_VMC_UNREGISTER_INTERFACE_ENABLED 1
#define TRACE_SPICE_VMC_EVENT_ENABLED 1

#define TRACE_WCT_INIT_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_init(void)
{
}

static inline void trace_wct_init(void)
{
    if (true) {
        _nocheck__trace_wct_init();
    }
}

#define TRACE_WCT_CMD_RE_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_cmd_re(void)
{
}

static inline void trace_wct_cmd_re(void)
{
    if (true) {
        _nocheck__trace_wct_cmd_re();
    }
}

#define TRACE_WCT_CMD_ST_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_cmd_st(void)
{
}

static inline void trace_wct_cmd_st(void)
{
    if (true) {
        _nocheck__trace_wct_cmd_st();
    }
}

#define TRACE_WCT_CMD_SP_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_cmd_sp(void)
{
}

static inline void trace_wct_cmd_sp(void)
{
    if (true) {
        _nocheck__trace_wct_cmd_sp();
    }
}

#define TRACE_WCT_CMD_TS_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_cmd_ts(int input)
{
}

static inline void trace_wct_cmd_ts(int input)
{
    if (true) {
        _nocheck__trace_wct_cmd_ts(input);
    }
}

#define TRACE_WCT_CMD_OTHER_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_cmd_other(const char * cmd)
{
}

static inline void trace_wct_cmd_other(const char * cmd)
{
    if (true) {
        _nocheck__trace_wct_cmd_other(cmd);
    }
}

#define TRACE_WCT_SPEED_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_wct_speed(int speed)
{
}

static inline void trace_wct_speed(int speed)
{
    if (true) {
        _nocheck__trace_wct_speed(speed);
    }
}

#define TRACE_SPICE_VMC_WRITE_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_spice_vmc_write(ssize_t out, int len)
{
}

static inline void trace_spice_vmc_write(ssize_t out, int len)
{
    if (true) {
        _nocheck__trace_spice_vmc_write(out, len);
    }
}

#define TRACE_SPICE_VMC_READ_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_spice_vmc_read(int bytes, int len)
{
}

static inline void trace_spice_vmc_read(int bytes, int len)
{
    if (true) {
        _nocheck__trace_spice_vmc_read(bytes, len);
    }
}

#define TRACE_SPICE_VMC_REGISTER_INTERFACE_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_spice_vmc_register_interface(void * scd)
{
}

static inline void trace_spice_vmc_register_interface(void * scd)
{
    if (true) {
        _nocheck__trace_spice_vmc_register_interface(scd);
    }
}

#define TRACE_SPICE_VMC_UNREGISTER_INTERFACE_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_spice_vmc_unregister_interface(void * scd)
{
}

static inline void trace_spice_vmc_unregister_interface(void * scd)
{
    if (true) {
        _nocheck__trace_spice_vmc_unregister_interface(scd);
    }
}

#define TRACE_SPICE_VMC_EVENT_BACKEND_DSTATE() ( \
    false)

static inline void _nocheck__trace_spice_vmc_event(int event)
{
}

static inline void trace_spice_vmc_event(int event)
{
    if (true) {
        _nocheck__trace_spice_vmc_event(event);
    }
}
#endif /* TRACE_CHARDEV_GENERATED_TRACERS_H */
