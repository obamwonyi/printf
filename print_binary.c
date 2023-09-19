#include "main.h"

/**
 * print_binary - Prints a number of the binary form.
 * @num: The number.
 * @i: Pointer to the number of characters printed.
 * Return: void
 */
void print_binary(int num, int *i)
{
	char c;

	if (num / 2)
		print_binary(num / 2, i);
	c = '0' + (num % 2);
	write(1, &c, 1);
	*i = *i + 1;
}

