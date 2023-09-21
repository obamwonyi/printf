#include "main.h"

/**
*print_binary - print positive
*@num: long type
*@i: pointer to int
*Return:void
*/
void print_binary(unsigned int num, int *i)
{
	char c;

	if (num / 2)
		print_binary(num / 2, i);
	c = '0' + (num % 2);
	write(1, &c, 1);
	*i = *i + 1;
}
