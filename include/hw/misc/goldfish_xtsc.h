/* Copyright (C) 2017 The Android Open Source Project
**
** This software is licensed under the terms of the GNU General Public
** License version 2, as published by the Free Software Foundation, and
** may be copied, distributed, and modified under those terms.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
*/
#ifndef _HW_GOLDFISH_XTSC_H
#define _HW_GOLDFISH_XTSC_H

#define TYPE_GOLDFISH_XTSC     "goldfish_xtsc"
#define GOLDFISH_XTSC_DEV_ID   "goldfish_xtsc"
#define GOLDFISH_XTSC_ADDR_PROP "addr"
#define GOLDFISH_XTSC_SIZE_PROP "size"
#define GOLDFISH_XTSC_NAME_PROP "name"
#define GOLDFISH_XTSC_COMM_ADDR_PROP "comm_addr"
#define GOLDFISH_XTSC_RESERVED_SIZE_PROP "reserved_size"
#define GOLDFISH_XTSC_DSP_IRQ_ADDR_PROP "dsp_irq_addr"
#define GOLDFISH_XTSC_DSP_IRQ_PROP "dsp_irq"

struct Object;
Object **goldfish_xtsc_devices(void);
hwaddr goldfish_xtsc_get_addr(Object *obj, int i);
uint64_t goldfish_xtsc_get_size(Object *obj, int i);

#endif /* _HW_GOLDFISH_XTSC_H */

