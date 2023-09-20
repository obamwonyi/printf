#include "main.h"
#include <stdlib.h>

char *strrev(char *str, int len)
{
	char tmp;
	int i;

	for (i = 0; i < (len / 2); i++)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
	return (str);
}
void print_positive(long num, int *i)
{
	char c;

	if (num / 2)
		print_positive(num / 2, i);
	c = '0' + (num % 2);
	write(1, &c, 1);
	*i = *i + 1;
}

void print_negative(long num, int *i)
{
	char *number;
	int j;

	number = malloc(32 * sizeof(char));
	if (number != NULL)
	{
		for (j = 0; j < 32; j++)
			number[j] = '1';
		for (j = 0; !(num / 2); j++)
		{
			if (num % 2)
				number[j] = '0';
			else
				number[j] = '1';
		}
		if (num % 2)
			number[j] = '0';
		else
			number[j] = '1';
		number = strrev(number, 32);
		for (j = 0; j < 32; j++)
		{
			write(1, number + j, 1);
			*i = *i + 1;
		}
		free(number);
	}
}

void print_binary(long num, int *i)
{
	if (num >= 0)
		print_positive(num, i);
	else
	{
		num = -num - 1;
		print_negative(num, i);
	}
}

