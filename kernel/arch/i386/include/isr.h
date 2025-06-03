#ifndef _HAL_ISR_H
#define _HAL_ISR_H

#include <stdint.h>

struct registers
{
    uint32_t ds;
    uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
};

void isr_install();
void isr_handler(struct registers *r);

#endif