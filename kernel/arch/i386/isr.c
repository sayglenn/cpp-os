#include <isr.h>
#include <idt.h>
#include <stdio.h>

void isr_handler(struct registers *r)
{
    printf("Received interrupt: %d\n", r->int_no);
}

void isr_install()
{
    for (int i = 0; i < 32; i++)
    {
        set_idt_gate(i, (uint32_t)isr_stub_table[i]);
    }
}