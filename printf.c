#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void print_char(va_list ap, int *i)
{
	char c;
	
	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	*i = *i + 1;
}

void print_string(va_list ap, int *i)
{
	char *str;
	char c;
	int j;

	str = va_arg(ap, char *);
	if (str != NULL)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			 c = str[j];
		 	write(1, &c, 1);
			*i = *i + 1;
		}
	}
}

void print_origin(char c, int *i)
{
	write(1, &c, 1);
	*i = *i + 1;
}


int _printf(const char *format, ...)
{
	int i, count;
	va_list ap;

	va_start(ap, format);
	count = 0;
	if (format != NULL)
	{
		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				i++;
				if (format[i] == 'c')
					print_char(ap, &count);
				else if (format[i] == '%')
					print_origin(format[i], &count);
				else if (format[i] == 's')
					print_string(ap, &count);
				else
				{
					print_origin(format[i - 1], &count);
					print_origin(format[i], &count);
				}
			}
			else
				print_origin(format[i], &count);
		}
		va_end(ap);
	}
	return (count);
}