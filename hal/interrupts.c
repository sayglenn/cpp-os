#include "interrupts.h"

void enable_interrupts(void)
{
    __asm__ volatile("sti");
}

void disable_interrupts(void)
{
    __asm__ volatile("cli");
}