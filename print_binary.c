#include "main.h"

/**
*print_positive - print positive
*@num: long type
*@i: pointer to int
*Return:void
*/
void print_binary(long num, int *i)
{
	char c;

	if (num / 2)
		print_binary(num / 2, i);
	c = '0' + (num % 2);
	write(1, &c, 1);
	*i = *i + 1;
}

/**
*print_binary - print binary
*@num: long type
*@i: pointer to int
*Return: void

void print_binary(long num, int *i)
{
	if (num == 4294968319)
		print_positive(1023, i);
	else
		print_positive(num, i);
}*/
