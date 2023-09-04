/*
 * EEET2490 Embedded OS and interface
 * Phan Hoang Son - s3715412
*/

#include "../inc/kernel.h"
#include "Delay and Uart functions.c"



//========================MAIN============================//

void main()
{
    // set up serial console

	uart_puts("                                                                                                                                                                                                                          \n");
	uart_puts("                                                                                                                                                                                                                          \n");
	uart_puts("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEETTTTTTTTTTTTTTTTTTTTTTT 222222222222222        444444444     999999999          000000000                                                               \n");
	uart_puts("E::::::::::::::::::::EE::::::::::::::::::::EE::::::::::::::::::::ET:::::::::::::::::::::T2:::::::::::::::22     4::::::::4   99:::::::::99      00:::::::::00                                                             \n");
	uart_puts("E::::::::::::::::::::EE::::::::::::::::::::EE::::::::::::::::::::ET:::::::::::::::::::::T2::::::222222:::::2   4:::::::::4 99:::::::::::::99  00:::::::::::::00                                                           \n");
	uart_puts("EE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::EEE::::::EEEEEEEEE::::ET:::::TT:::::::TT:::::T2222222     2:::::2  4::::44::::49::::::99999::::::90:::::::000:::::::0                                                          \n");
	uart_puts("  E:::::E       EEEEEE  E:::::E       EEEEEE  E:::::E       EEEEEETTTTTT  T:::::T  TTTTTT            2:::::2 4::::4 4::::49:::::9     9:::::90::::::0   0::::::0                                                          \n");
	uart_puts("  E:::::E               E:::::E               E:::::E                     T:::::T                    2:::::24::::4  4::::49:::::9     9:::::90:::::0     0:::::0                                                          \n");
	uart_puts("  E::::::EEEEEEEEEE     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE           T:::::T                 2222::::24::::4   4::::4 9:::::99999::::::90:::::0     0:::::0                                                          \n");
	uart_puts("  E:::::::::::::::E     E:::::::::::::::E     E:::::::::::::::E           T:::::T            22222::::::224::::444444::::44499::::::::::::::90:::::0 000 0:::::0                                                          \n");
	uart_puts("  E:::::::::::::::E     E:::::::::::::::E     E:::::::::::::::E           T:::::T          22::::::::222  4::::::::::::::::4  99999::::::::9 0:::::0 000 0:::::0                                                          \n");
	uart_puts("  E::::::EEEEEEEEEE     E::::::EEEEEEEEEE     E::::::EEEEEEEEEE           T:::::T         2:::::22222     4444444444:::::444       9::::::9  0:::::0     0:::::0                                                          \n");
	uart_puts("  E:::::E               E:::::E               E:::::E                     T:::::T        2:::::2                    4::::4        9::::::9   0:::::0     0:::::0                                                          \n");
	uart_puts("  E:::::E       EEEEEE  E:::::E       EEEEEE  E:::::E       EEEEEE        T:::::T        2:::::2                    4::::4       9::::::9    0::::::0   0::::::0                                                          \n");
	uart_puts("EE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::EEE::::::EEEEEEEE:::::E      TT:::::::TT      2:::::2       222222       4::::4      9::::::9     0:::::::000:::::::0                                                          \n");
	uart_puts("E::::::::::::::::::::EE::::::::::::::::::::EE::::::::::::::::::::E      T:::::::::T      2::::::2222222:::::2     44::::::44   9::::::9       00:::::::::::::00                                                           \n");
	uart_puts("E::::::::::::::::::::EE::::::::::::::::::::EE::::::::::::::::::::E      T:::::::::T      2::::::::::::::::::2     4::::::::4  9::::::9          00:::::::::00                                                             \n");
	uart_puts("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE      TTTTTTTTTTT      22222222222222222222     4444444444 99999999             000000000                                                               \n");
	uart_puts("BBBBBBBBBBBBBBBBB                                                                                                                      tttt                            lllllll           OOOOOOOOO        SSSSSSSSSSSSSSS \n");
	uart_puts("B::::::::::::::::B                                                                                                                  ttt:::t                            l:::::l         OO:::::::::OO    SS:::::::::::::::S\n");
	uart_puts("B::::::BBBBBB:::::B                                                                                                                 t:::::t                            l:::::l       OO:::::::::::::OO S:::::SSSSSS::::::S\n");
	uart_puts("BB:::::B     B:::::B                                                                                                                t:::::t                            l:::::l      O:::::::OOO:::::::OS:::::S     SSSSSSS\n");
	uart_puts("  B::::B     B:::::B  aaaaaaaaaaaaa  rrrrr   rrrrrrrrr       eeeeeeeeeeee            mmmmmmm    mmmmmmm       eeeeeeeeeeee    ttttttt:::::ttttttt      aaaaaaaaaaaaa    l::::l      O::::::O   O::::::OS:::::S            \n");
	uart_puts("  B::::B     B:::::B  a::::::::::::a r::::rrr:::::::::r    ee::::::::::::ee        mm:::::::m  m:::::::mm   ee::::::::::::ee  t:::::::::::::::::t      a::::::::::::a   l::::l      O:::::O     O:::::OS:::::S            \n");
	uart_puts("  B::::BBBBBB:::::B   aaaaaaaaa:::::ar:::::::::::::::::r  e::::::eeeee:::::ee     m::::::::::mm::::::::::m e::::::eeeee:::::eet:::::::::::::::::t      aaaaaaaaa:::::a  l::::l      O:::::O     O:::::O S::::SSSS         \n");
	uart_puts("  B:::::::::::::BB             a::::arr::::::rrrrr::::::re::::::e     e:::::e     m::::::::::::::::::::::me::::::e     e:::::etttttt:::::::tttttt               a::::a  l::::l      O:::::O     O:::::O  SS::::::SSSSS    \n");
	uart_puts("  B::::BBBBBB:::::B     aaaaaaa:::::a r:::::r     r:::::re:::::::eeeee::::::e     m:::::mmm::::::mmm:::::me:::::::eeeee::::::e      t:::::t              aaaaaaa:::::a  l::::l      O:::::O     O:::::O    SSS::::::::SS  \n");
	uart_puts("  B::::B     B:::::B  aa::::::::::::a r:::::r     rrrrrrre:::::::::::::::::e      m::::m   m::::m   m::::me:::::::::::::::::e       t:::::t            aa::::::::::::a  l::::l      O:::::O     O:::::O       SSSSSS::::S \n");
	uart_puts("  B::::B     B:::::B a::::aaaa::::::a r:::::r            e::::::eeeeeeeeeee       m::::m   m::::m   m::::me::::::eeeeeeeeeee        t:::::t           a::::aaaa::::::a  l::::l      O:::::O     O:::::O            S:::::S\n");
	uart_puts("  B::::B     B:::::Ba::::a    a:::::a r:::::r            e:::::::e                m::::m   m::::m   m::::me:::::::e                 t:::::t    tttttta::::a    a:::::a  l::::l      O::::::O   O::::::O            S:::::S\n");
	uart_puts("BB:::::BBBBBB::::::Ba::::a    a:::::a r:::::r            e::::::::e               m::::m   m::::m   m::::me::::::::e                t::::::tttt:::::ta::::a    a:::::a l::::::l     O:::::::OOO:::::::OSSSSSSS     S:::::S\n");
	uart_puts("B:::::::::::::::::B a:::::aaaa::::::a r:::::r             e::::::::eeeeeeee       m::::m   m::::m   m::::m e::::::::eeeeeeee        tt::::::::::::::ta:::::aaaa::::::a l::::::l      OO:::::::::::::OO S::::::SSSSSS:::::S\n");
	uart_puts("B::::::::::::::::B   a::::::::::aa:::ar:::::r              ee:::::::::::::e       m::::m   m::::m   m::::m  ee:::::::::::::e          tt:::::::::::tt a::::::::::aa:::al::::::l        OO:::::::::OO   S:::::::::::::::SS \n");
	uart_puts("BBBBBBBBBBBBBBBBB     aaaaaaaaaa  aaaarrrrrrr                eeeeeeeeeeeeee       mmmmmm   mmmmmm   mmmmmm    eeeeeeeeeeeeee            ttttttttttt    aaaaaaaaaa  aaaallllllll          OOOOOOOOO      SSSSSSSSSSSSSSS   \n");
	uart_puts("                                                                                                                                                                                                                          \n");
	uart_puts("                                                                                                                                                                                                                          \n");
	uart_puts("                                                                                                                                                                                                                          \n");
	uart_puts("                                                                                                                                                                                                                          \n");
	
	printf("		Developed by <Phan Hoang Son>	-	<s3715412>\n");
	printf("SaltOS>");
    // run CLI
    while(1) 
	{
    	cli();
    }
}

//=====================END of main========================//

//===================Function defination==================//

// compare if 2 string are the same or not
int my_strcmp(const char *s1, const char *s2) 
{
    while (*s1 != '\0' && *s2 != '\0') 
	{
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

// command line interpreter function
void cli()
{
	static char history[HISTORY_SIZE][MAX_CMD_SIZE];
	static char cli_buffer[MAX_CMD_SIZE];
	static int index = 0;

	static int history_index = 0;
	static int scroll = 0;

	//read each char
	char c = uart_getc();

	switch (c)
	{
		case '\n': // when user press enter
			uart_sendc(c);
			cli_buffer[index] = '\0';

			// examine user input:
			check_command(cli_buffer);

			// save user input into history array, wrap over when there are 10 entries.
			int i = 0;
			while (cli_buffer[i] != '\0')
			{
				history[history_index][i] = cli_buffer[i];
				i++;
			}
			history[history_index][i] = '\0';
			scroll = history_index;
			history_index++;

			if (history_index == 10)
			{
				history_index = 0;
			}

			index = 0;
			uart_puts("\nSaltOS>");
			break;
		case '\b': // when user press backspace
			// Backspace only works when user have typed something
			if (index > 0)
			{
				uart_sendc(c);
				uart_sendc(' '); 
				uart_sendc('\b');
				index--;
			}
			break;
		case '+':	// User scrolling back command history
			// check if we have reached the earliest command line
			if (scroll >= 0) 
			{	
				// check if there is a command line history has been printed out on the CLI
				int prev_index = 0;
				if (history[scroll+1][0] != 0)	
				{
					// if yes, delete that line before print out a new line
					while (history[scroll+1][prev_index] != '\0')
					{
						prev_index++;
					}
					
					while(prev_index > 0)
					{	
						uart_sendc('\b');
						uart_sendc(' '); 
						uart_sendc('\b');
						prev_index--;
					}
				}
				// print out the command line history
              	uart_puts(history[scroll]);
				// write back to cli_buffer
				while (history[scroll][index] != '\0')
				{
					cli_buffer[index] = history[scroll][index]; 
					index++;
				}
				scroll--;
			}
            break;
		case '_': 	// User scrolling forward command history
			// check if we have reached the most recent command line
			if (scroll < history_index) 
			{	
				// delete the line that '+' function has just printed above
				while(index > 0)
				{	
					uart_sendc('\b');
					uart_sendc(' '); 
					uart_sendc('\b');
					index--;
				}
              	uart_puts(history[scroll+1]);
				// write back to cli_buffer
				while (history[scroll+1][index] != '\0')
				{
					cli_buffer[index] = history[scroll+1][index]; 
					index++;
				}
				scroll++;
            }
            break;
		default:
			uart_sendc(c);
			cli_buffer[index] = c; //Store into the buffer
			index++; // increase buffer size +1 to store the next character
	}
}

// Check for valid command
void check_command(char *cli_buffer)
{
	// define function pointer to point to a function
	typedef void (*command_handler)(char*);

	// define a struct contains function name and function pointer.
	typedef struct 
	{
		char *name;
		command_handler handler;
	} command;

	// define an array with defined function name and function handler.
	command command_table[] = 
	{
		{"help", help},
		{"clear", clear},
		{"setcolor", set_color},
		{"showinfo", showinfo}
	};

	static char user_command[20];

	int count = 0; // counter to loop through cli_buffer array
	
	// loop through the first word of user input.
	while ((cli_buffer[count] != '\0') && cli_buffer[count] != ' ')
	{
		// store first word into user_command array
		user_command[count] = cli_buffer[count];
		count++;
	}
	user_command[count] = '\0'; // manually write \0 to the end of the array

	// loop through command table and check if user commmand is valid:
	for (int i = 0; i < sizeof(command_table) / sizeof(command_table[0]); i++) 
	{
        if (!my_strcmp(user_command, command_table[i].name)) 
		{
			command_table[i].handler(cli_buffer);
            return; // Exit the loop if a command is found
        } 	
    }
	uart_puts("Syntax error. Please type <help> to see valid commands");
	uart_sendc('\n');
}

// clear CLI:
void clear ()
{
	uart_puts("\033[2J\033[H"); // scroll and return pointer to home
	uart_puts("\033[0m"); // reset text and text background 
}

// printing <help> command lines
void help(char *cli_buffer)
{
	// define help entry struct and help table:
	typedef struct 
	{
		char *name;
		char *description;
		char *usage;
	} help_struct;

	help_struct help_table[] = 
	{
		{"help", "Display information about commands.", "help <command>"},
		{"clear", "Clear the terminal and reset color.", "clear"},
		{"setcolor", "Set text and background colors.", "setcolor -t <color> -b <color>\n> Available color: black, red, green, yellow, blue, purple, cyan, white."},
		{"showinfo", "Show board information.", "showinfo"}
	};

	static char user_option[20];
	if (cli_buffer[4] == '\0')  // if user only entered <help>
	{
		uart_puts("List of commands:\n");
		for (int i = 0; i < sizeof(help_table) / sizeof(help_table[0]); i++) 
		{
			uart_puts("> ");
			uart_puts(help_table[i].name);
			uart_puts(": ");
			uart_puts(help_table[i].description);
			uart_sendc('\n');
		}
    } 
	else // if user keep typing after <help>
	{
		int count = 5; // Jump to the character after the \n char
		// loop through the array until end of line
		while (cli_buffer[count] != '\0')
		{
			// store user's option to user_option array
			user_option[count-5] = cli_buffer[count];
			count++;
		}
		user_option[count-5] = '\0'; // manually write \0 to the end of the array
        // Find the specified command's usage info
        for (int i = 0; i < sizeof(help_table) / sizeof(help_table[0]); i++) 
		{
            if (!my_strcmp(user_option, help_table[i].name)) 
			{
				uart_puts("> ");
                uart_puts(help_table[i].name);
                uart_puts(": ");
                uart_puts(help_table[i].description);
                uart_puts("\n> Usage: ");
                uart_puts(help_table[i].usage);
				uart_sendc('\n');
                return; //return to main
            } 
        }
		uart_puts("help <command> syntax error. Please type <help> to see valid commands");
		uart_sendc('\n');
    }
}

// set color function
void set_color(char *cli_buffer)
{
	char text[8];	// array to store text color input
	char background[8];	// array to store background color input
	int count = 0;	// counter to loop through cli_buffer array
	int t = 0;	//counter to loop through text array
	int b = 0;	// counter to loop through background array
	// int fail_flag_t = 0; // flag to keep track of syntax error for text color command
	// int fail_flag_b = 0; // flag to keep track of syntax error for background color command

	typedef struct 
	{
		char *color_name;
		char *color_code;
	} color_entry;

	color_entry color_table[] = 
	{
		{"black", "0m"},
		{"red", "1m"},
		{"green", "2m"},
		{"yellow", "3m"},
		{"blue", "4m"},
		{"purple", "5m"},
		{"cyan", "6m"},
		{"white", "7m"}
	};

	// Loop through array cli_buffer till newline character 
	while(cli_buffer[count] != '\0')
	{
		// if current char is '-' and the char after it is 't' -> user is choosing text color
		if((cli_buffer[count] == '-') && (cli_buffer[count+1] == 't'))
		{
			// fail_flag_t = 1; // Raise the error flag for text color
			count = count+3;
			// keep looping until the next space or new line character
			while((cli_buffer[count+1] != '-') && (cli_buffer[count] != '\0'))
			{	
				// save the user input color into text[] array;
				text[t] = cli_buffer[count];
				count++;
				t++;
			}
			text[t] = '\0'; // manually write \0 to the end of the array
			
			// loop through color_table and find the match between user's command and existing color:
			for (int i = 0; i < sizeof(color_table)/sizeof(color_table[0]); i++)
			{
				if(!my_strcmp(text, color_table[i].color_name))
				{
					uart_puts("\033[3");
					uart_puts(color_table[i].color_code);
					// text[0] = '\0'; // clear the array
					// fail_flag_t= 0; // clear the error flag
				}
			}
			
		}
		// if current char is '-' and the char after it is 'b' -> user is choosing background color
		if((cli_buffer[count] == '-') && (cli_buffer[count+1] == 'b'))
		{
			// fail_flag_b = 1; // raise the error flag for background color
			count = count+3;
			while((cli_buffer[count+1] != '-') && (cli_buffer[count] != '\0'))
			{
				background[b] = cli_buffer[count];
				count++;
				b++;
			}
			background[b] = '\0'; // manually write \0 to the end of the array
			for (int i = 0; i < sizeof(color_table)/sizeof(color_table[0]); i++)
			{
				if(!my_strcmp(background, color_table[i].color_name))
				{
					uart_puts("\033[4");
					uart_puts(color_table[i].color_code);
					// background[0] = '\0'; //clear the array
					// fail_flag_b = 0; //clear the error flag
				}
			}
		}
		count++;
	}
}

void showinfo()
{
	// get board MAC address
	mbox[0] = 8 * 4;        		// Message Buffer Size in bytes (8 elements * 4 bytes (32 bit) each)
	mbox[1] = MBOX_REQUEST; 		// Message Request Code (this is a request message)
	mbox[2] = MBOX_TAG_MACADDRESS;  // TAG Identifier: Get MAC Address.
	mbox[3] = 6;            		// Value buffer size in bytes (max of request and response lengths)
	mbox[4] = 0;            		// REQUEST CODE = 0
	mbox[5] = 0;            		// 
	mbox[6] = 0;            		// clear output buffer (response data are mbox[5] & mbox[6])
	mbox[7] = MBOX_TAG_LAST;

	if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
	{
		printf("> Board MAC Address: %d%d\n", mbox[5], mbox[6]);
	}
	// get board revision
	mbox[0] = 7 * 4;        			// Message Buffer Size in bytes (7 elements * 4 bytes (32 bit) each)
	mbox[1] = MBOX_REQUEST; 			// Message Request Code (this is a request message)
	mbox[2] = MBOX_TAG_BOARDREVISION;  	// TAG Identifier: Get MAC Address.
	mbox[3] = 4;            			// Value buffer size in bytes (max of request and response lengths)
	mbox[4] = 0;            			// REQUEST CODE = 0
	mbox[5] = 0;            			// RESPOND 
	mbox[6] = MBOX_TAG_LAST;            // 
	// mbox[7] = MBOX_TAG_LAST;

	if (mbox_call(ADDR(mbox), MBOX_CH_PROP))
	{
		// uart_puts("Board Revision: ");
		// uart_dec(mbox[5]);
		// uart_puts("\n");
		printf("> Board Revision: %x\n", mbox[5]);
	}
}