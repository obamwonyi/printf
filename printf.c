#include "main.h"

/**
 * number_handeler - Handels all types of numbers.
 * @c: The specifier.
 * @ap: The poiner to next argument in the printf function.
 * @i: The address to the counter of characters number printed.
 *
 */
void number_handeler(char c, va_list ap, int *i)
{
	if (format[i] == 'i' || format[i] == 'd')
		print_int(ap, &count);
	else if (format[i] == 'b')
		print_binary(va_arg(ap, long), &count);
	else if (format[i] == 'u')
		print_unsigned_int(ap, &count);
	else if (format[i] == 'o')
		print_octal(ap, &count);
	else if (format[i] == 'x')
		print_hex_lower(ap, &count);
	else if (format[i] == 'X')
		print_hex_upper(ap, &count);
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
