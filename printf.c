#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - Prints char to the standard output.
 * @ap: The address of the char.
 * @i: The number of the characters printed.
 *
 */
void print_char(va_list ap, int *i)
{
	char c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	*i = *i + 1;
}

/**
 * print_string - Prints a string to the standard output.
 * @ap: A pointer to the string.
 * @i: The number of characters printed.
 *
 */
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

/**
 * print_origin - Prints the origing char from the format argument to stdout.
 * @c: The character.
 * @i: The numbers of characters printed.
 *
 */
void print_origin(char c, int *i)
{
	write(1, &c, 1);
	*i = *i + 1;
}

/**
 * _printf - produces output accouding th a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
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
			}
			else
				print_origin(format[i], &count);
		}
	}
	va_end(ap);
	return (count);
}
