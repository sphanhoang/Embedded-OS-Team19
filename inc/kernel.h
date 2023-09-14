#include "printf.h"
#include "delay.h"
#include "framebf.h"
#include "uart1.h"



#define MAX_CMD_SIZE 100
#define HISTORY_SIZE 10

//===========Function declaration=========================//

int my_strcmp(const char *s1, const char *s2);
void cli();
void check_command(char *cli_buffer);
void clear ();
void help(char *cli_buffer);
void set_color(char *cli_buffer);
void showinfo();
void draw();
void write();
void *memcpy(void *dest, const void *src, size_t n);