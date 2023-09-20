#include "main.h"
/**
*other_special_char - handles other special char
*@c: character
*@i: int
*Return: void
*/
void other_special_char(char c, int *i)
{
	switch (c)
	{
		case '\v':
			write(1, "\\v", 2);
			*i += 2;
			break;
		case '\f':
			write(1, "\\f", 2);
			*i += 2;
			break;
		case '\\':
			write(1, "\\\\", 2);
			*i += 2;
			break;
		case '\'':
			write(1, "\\'", 2);
			*i += 2;
			break;
		case '\"':
			write(1, "\\\"", 2);
			*i += 2;
			break;
		default:
			write(1, &c, 1);
			(*i)++;
	}
}
