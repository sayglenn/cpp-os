#ifndef _HAL_IDT_H
#define _HAL_IDT_H

#include <stdint.h>

#define IDT_ENTRIES 256

struct idt_entry_t
{
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed));

struct idt_ptr_t
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

void idt_set_gate(int n, uint32_t isr, uint16_t sel, uint8_t flags);
void idt_load();

#endif