#include <stdio.h>

#include <kernel/tty.h>

extern "C" void kernel_main(void)
{
    /* Initialize terminal interface */
    terminal_initialize();
    printf("Hello, kernel World!\n");
}