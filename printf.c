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
		print_binary(va_arg(ap, unsigned int), i);
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
 * specifier_checker - Checks if the format is one of number specifiers.
 * @format: The format specifier.
 *
 * Return: 1 if the format matcahs one of number specifiers, otherwise 0.
 */
int specifier_checker(char format)
{
	char num_spec[7] = "idbuoxX";
	int i;

	for (i = 0; i < 7; i++)
	{
		if (format == num_spec[i])
			return (1);
	}
	return (0);
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
			else if (specifier_checker(format[i]))
				number_handeler(format[i], ap, &count);
			else if (format[i] == '%')
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
