#ifndef DELAY_H
#define DELAY_H

#include "uart1.h"

unsigned int uart_isReadByteReady();
unsigned char getUart();
void wait_msec(unsigned int n);
void set_wait_timer(int set, unsigned int msVal) ;

#endif