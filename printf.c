#include "main.h"

/**
*print_char - handlse char
*@ap: va_list
*@i: int
*Return: void
*/
void print_char(va_list ap, int *i)
{
	char c;

	c = (char)va_arg(ap, int);
	write(1, &c, 1);
	*i = *i + 1;
}

/**
*print_string - handles string
*@ap: va_list
*@i: int
*Return: void
*/
void print_string(va_list ap, int *i)
{
	char *str = va_arg(ap, char *);
	int j;

	if (str != NULL)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			write(1, &str[j], 1);
			(*i)++;
		}
	}
	else
	{
		char *nullStr = "(null)";
		int j;

		for (j = 0; nullStr[j] != '\0'; j++)
		{
			write(1, &nullStr[j], 1);
			(*i)++;
		}
	}
}

/**
*print_origin - default
*@c: char
*@i: int
*Return: void
*/
void print_origin(char c, int *i)
{
	write(1, &c, 1);
	(*i)++;
}

/**
*print_int - handle int
*@ap: va_list
*@i: int
*Return: void
*/
void print_int(va_list ap, int *i)
{
	int num = va_arg(ap, int);
	char buffer[20];
	int written = snprintf(buffer, sizeof(buffer), "%d", num);

	if (written >= 0 && written < ((int)sizeof(buffer)))
	{
		write(1, buffer, written);
		*i += written;
	}
}

/**
*_printf - mimics the printf function
*@format: the string to be formatted
*Return: num of char printed
*/
int _printf(const char *format, ...)
{
	int i, count;
	va_list ap;

	va_start(ap, format);
	count = 0;
	if (format == NULL)
		return (-1);
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
			else if (format[i] == 'i' || format[i] == 'd')
				print_int(ap, &count);
			else if (format[i] == 'b')
				print_binary(va_arg(ap, int), &count);
			else
			{
				fprintf(stderr, "Unknown format specifier: %%%c\n", format[i]);
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
