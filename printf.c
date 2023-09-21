#include "main.h"

/**
 * number_handeler - Handels all types of numbers.
 * @format: The specifier.
 * @ap: The poiner to next argument in the printf function.
 * @i: The address to the counter of characters number printed.
 *
 */
void number_handeler(char format, va_list ap, int *i)
{
	if (format == 'i' || format == 'd')
		print_int(ap, i);
	else if (format == 'b')
		print_binary(va_arg(ap, long), i);
	else if (format == 'u')
		print_unsigned_int(ap, i);
	else if (format == 'o')
		print_octal(ap, i);
	else if (format == 'x')
		print_hex_lower(ap, i);
	else if (format == 'X')
		print_hex_upper(ap, i);
}

/**
*_printf - mimics the printf function
*@format: the string to be formatted
*Return: num of char printed
*/
int _printf(const char *format, ...)
{
	int i, count = 0;
	va_list ap;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			number_handeler(format[i], ap, &count);
			if (format[i] == '%')
				print_origin(format[i], &count);
			else if (format[i] == 'c')
				print_char(ap, &count);
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
	return (count);
}
