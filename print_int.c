#include "main.h"

/**
*print_int - handle int
*@ap: va_list
*@i: int
*Return: void
*/
void print_int(va_list ap, int *i)
{
	int num = va_arg(ap, int);
	char buffer[1024];
	int written = snprintf(buffer, sizeof(buffer), "%d", num);

	if (written >= 0 && written < ((int)sizeof(buffer)))
	{
		write(1, buffer, written);
		*i += written;
	}
}
