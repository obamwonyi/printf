#include "main.h"

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
