#include "main.h"

/**
*print_char - handles char
*@ap: va_list
*@i: int
*Return: void
*/
void print_char(va_list ap, int *i)
{
	char c = (char)va_arg(ap, int);
	char buffer[1024];
	int bufferIndex = 0;

	if (bufferIndex >= ((int) sizeof(buffer) - 1))
	{
		write(1, buffer, bufferIndex);
		*i += bufferIndex;
		bufferIndex = 0;
	}

	buffer[bufferIndex++] = c;

	if (bufferIndex > 0)
	{
		write(1, buffer, bufferIndex);
		*i += bufferIndex;
	}
}
