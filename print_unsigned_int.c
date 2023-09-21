#include "main.h"

/**
 * print_unsigned_int - handles printing an unsigned integer
 * @ap: va_list
 * @i: pointer to the count of printed characters
 * Return: void
 */
void print_unsigned_int(va_list ap, int *i)
{
	unsigned int num = va_arg(ap, unsigned int);
	char buffer[1024];
	int bufferIndex = 0;
	int written = snprintf(buffer, sizeof(buffer), "%u", num);

	if (written >= 0 && written < ((int)sizeof(buffer)))
	{
		if (bufferIndex + written >= ((int)sizeof(buffer) - 1))
		{
			write(1, buffer, bufferIndex);
			(*i) += bufferIndex;
			bufferIndex = 0;
		}
		memcpy(buffer + bufferIndex, buffer, written);
		bufferIndex += written;
	}

	if (bufferIndex > 0)
	{
		write(1, buffer, bufferIndex);
		(*i) += bufferIndex;
	}
}
