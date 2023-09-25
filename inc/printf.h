#ifndef PRINTF_H
#define PRINTF_H

#include "../gcclib/stddef.h"
#include "../gcclib/stdint.h"
#include "../gcclib/stdarg.h"
#include "uart1.h"

void printf(char *string,...);

#endif