#ifndef HAL_IO_H
#define HAL_IO_H

#include <stdint.h>

uint8_t inb(uint16_t port);
void outb(uint16_t port, uint8_t val);
void io_wait(void);

#endif
