#include "main.h"


/**
*_printf - a function that mimics stdio.h library printf() function
*@format: the string to be formated
*Return: the number of chars printed
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

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			numOfPrints++;
		}
		else
		{
			format++;
			numOfPrints += handleSpecifier(format, numOfPrints, args);
		}
		format++;
	}
	va_end(args);
	return (numOfPrints);
}

/**
*handleSpecifier - handles the i,d, s, c and % specifier
*@format : the string to format
*@args : the variadic argument int passed
*@numOfPrints : numbers of integers printed
*Return: int
*/
int handleSpecifier(const char *format, int numOfPrints, va_list args)
{
	switch (*format)
	{
		case 'c': {
		write(1, format, 1);
		numOfPrints++;
		break;
		}
		case 'i':
		case 'd': {
			handlesInt(format, args);
		break;
		}
		case '%'{
		write(1, format, 1);
		numOfPrints++;
		break;
		}
		case 's': {
		write(1, format, strlen(format));
		numOfPrints++;
		break;
		}
	}
	return (numOfPrints);
}

/**
*handlesInt - handle the i and d format specifier
*@format: the string to be formated
*@args: the variadic argument passed
*Return: void
*/
void handlesInt(const char *format, va_list args)
{
	int num = va_arg(args, int);
	char buffer[sizeof(format)];
	int length = 0;
	int is_negative = 0;
	int i = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}

	do {
		buffer[length++] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		buffer[length++] = '-';
	for (i = length - 1; i >= 0; i--)
	{
		write(1, &buffer[i], 1);
	}
}
