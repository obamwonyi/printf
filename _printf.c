#include "main.h"


/**
* _printf : does the same function of the stdio printf
 * format: number of arguments
 * ...: other functions
 * Return : int
*/
int _printf(const char *format, ...)
{
    va_list args;

    int numOfPrints = 0;

    if (format == NULL)
    {
        return (-1);
    }

    va_start(args, format);

    while(*format)
    {
        if(*format != '%')
        {
            write(1, format, 1);
            numOfPrints++;
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                {
                    write(1,format, 1);
                    numOfPrints++;
                    break;
                }

                case 'i':
                case 'd': {
                    int num = va_arg(args, int);
                    char buffer[sizeof (format)];
                    int length = 0;
                    int is_negative = 0;
                    int i = 0;

                    if (num < 0) {
                        is_negative = 1;
                        num = -num;
                    }

                    do {
                        buffer[length++] = num % 10 + '0';
                        num /= 10;
                    } while (num > 0);

                    if (is_negative) {
                        buffer[length++] = '-';
                    }

                    for (i = length - 1; i >= 0; i--) {
                        write(1, &buffer[i], 1);
                    }
                    break;
                }

                case 's':
                {
                    write(1,format, strlen(format));
                    numOfPrints++;
                    break;
                }
            }
        }

        format++;
    }

    va_end(args);

    return (numOfPrints);
}
