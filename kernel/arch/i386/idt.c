#include <idt.h>

#define IDT_ENTRIES 256

idt_entry_t idt[IDT_ENTRIES];
idt_ptr_t idt_reg;

extern void idt_load(uint32_t);

void idt_set_gate(int n, uint32_t handler)
{
    idt[n].low_offset = handler & 0xFFFF;
    idt[n].selector = 0x08; // kernel code segment
    idt[n].zero = 0;
    idt[n].type_attr = 0x8E; // present, ring 0, 32-bit interrupt gate
    idt[n].high_offset = (handler >> 16) & 0xFFFF;
}

void idt_init()
{
    idt_reg.base = (uint32_t)&idt;
    idt_reg.limit = sizeof(idt_entry_t) * IDT_ENTRIES - 1;

    for (int i = 0; i < IDT_ENTRIES; i++)
    {
        set_idt_gate(i, (uint32_t)isr_stub_table[i]);
    }

    load_idt((uint32_t)&idt_reg);
}