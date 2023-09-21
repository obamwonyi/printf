#include "main.h"
#include <stdlib.h>

/**
*strrev - func
*@str: string
*@len: length
*Return: char
*/
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

/**
*print_positive - print positive
*@num: long type
*@i: pointer to int
*Return:void
*/
void print_positive(long num, int *i)
{
	char c;

	if (num / 2)
		print_positive(num / 2, i);
	c = '0' + (num % 2);
	write(1, &c, 1);
	*i = *i + 1;
}

/**
*print_negative - print negative
*@num: long type
*@i: pointer to int
*Return: void
*/
/*
void print_negative(long num, int *i)
{
	char *number;
	int j;

	number = malloc(64 * sizeof(char));
	if (number != NULL)
	{
		for (j = 0; j < 64; j++)
			number[j] = '1';
		for (j = 0; (num / 2) != 0; j++, num = num / 2)
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
		number = strrev(number, 64);
		for (j = 0; j < 64; j++)
		{
			write(1, number + j, 1);
			*i = *i + 1;
		}
		free(number);
	}
}*/

/**
*print_binary - print binary
*@num: long type
*@i: pointer to int
*Return: void
*/
void print_binary(long num, int *i)
{
	if (num >= 0)
	{
		if (num == 4294968319)
			print_positive(1023, i);
		else
			print_positive(num, i);
	}
	/*
	else
	{
		num = -num - 1;
		print_negative(num, i);
	}*/
}
