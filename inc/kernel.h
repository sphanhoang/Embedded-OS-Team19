#include "../inc/uart1.h"
#include "../inc/mbox.h"
#include "../inc/printf.h"
#include "../inc/delay.h"
#include "../inc/framebf.h"

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