#include "../inc/printf.h"
#include "../inc/uart1.h"

#define MAX_PRINT_SIZE 256


void printf(char *string,...) 
{

	va_list ap;
	va_start(ap, string);

	char buffer[MAX_PRINT_SIZE];
	int buffer_index = 0;

	char temp_buffer[MAX_PRINT_SIZE];

	while(1) 
	{
		if (*string == 0)
			break;

		if (*string == '%') 
		{
			string++;

			if (*string == 'd') 
			{
				string++;
				int x = va_arg(ap, int);
				int temp_index = MAX_PRINT_SIZE - 1;

				do 
				{
					temp_buffer[temp_index] = (x % 10) + '0';
					temp_index--;
					x /= 10;
				} while(x != 0);

				for(int i = temp_index + 1; i < MAX_PRINT_SIZE; i++) {
					buffer[buffer_index] = temp_buffer[i];
					buffer_index++;
				}
			}
			else if (*string == 'x') 
			{
				string++;
                int x = va_arg(ap, int);
                int temp_index = MAX_PRINT_SIZE - 1;

                if (x == 0) 
				{
                    temp_buffer[temp_index] = '0';
                    temp_index--;
                } 
				else 
				{
                    while (x != 0) 
					{
                        int remainder = x % 16;
                        if (remainder < 10)
                            temp_buffer[temp_index] = remainder + '0';
                        else
                            temp_buffer[temp_index] = remainder - 10 + 'A';
                        temp_index--;
                        x /= 16;
                    }
                }

                for (int i = temp_index + 1; i < MAX_PRINT_SIZE; i++) 
				{
                    buffer[buffer_index] = temp_buffer[i];
                    buffer_index++;
                }
			}
			else if (*string == 'c') 
            {
                string++;
                char c_arg = va_arg(ap, int); 
                if (buffer_index < MAX_PRINT_SIZE - 1) 
                {
                    buffer[buffer_index++] = c_arg;
                }
            }
			else if (*string == 's') 
            {
                string++;
                char *str_arg = va_arg(ap, char*);
                while (*str_arg != '\0' && buffer_index < MAX_PRINT_SIZE - 1) 
                {
                    buffer[buffer_index++] = *str_arg;
                    str_arg++;
                }
            }
		
		}
		else 
		{
			buffer[buffer_index] = *string;
			buffer_index++;
			string++;
		}

		if (buffer_index == MAX_PRINT_SIZE - 1)
			break;
	}

	va_end(ap);

	buffer[buffer_index] = '\0';
	//Print out formated string
	uart_puts(buffer);
	buffer_index=0;
}
