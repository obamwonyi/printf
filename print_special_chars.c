#include "main.h"
/**
*print_special_char - handle special chars like \\n and \\t
*@c: character to handle
*@i: integer
*Return: void
*/
void print_special_char(char c, int *i)
{
	switch (c)
	{
		case '\n':
			write(1, "\\n", 2);
			*i += 2;
			break;
		case '\t':
			write(1, "\\t", 2);
			*i += 2;
			break;
		case '\r':
			write(1, "\\r", 2);
			*i += 2;
			break;
		default:
			write(1, &c, 1);
			(*i)++;
	}
}
