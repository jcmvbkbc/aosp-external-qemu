#include "qemu/osdep.h"
#include "qemu-common.h"
#include "qemu/main-loop.h"

#ifndef _MSC_VER
void qemu_fd_register(int fd)
{
}
#endif
