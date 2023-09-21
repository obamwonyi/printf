#include "main.h"


/**
*print_string - handles string
*@ap: va_list
*@i: int
*Return: void
*/
void print_string(va_list ap, int *i)
{
	char buffer[1024];
	char *str = va_arg(ap, char *);
	int bufferIndex = 0;
	int j;

	if (str != NULL)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			if (bufferIndex >= ((int)sizeof(buffer) - 1))
			{
				write(1, buffer, bufferIndex);
				(*i) += bufferIndex;
				bufferIndex = 0;
			}
			buffer[bufferIndex++] = str[j];
		}
	}
	else
	{
		char *nullStr = "(null)";

		for (j = 0; nullStr[j] != '\0'; j++)
		{
			if (bufferIndex >= ((int)sizeof(buffer) - 1))
			{
				write(1, buffer, bufferIndex);
				(*i) += bufferIndex;
				bufferIndex = 0;
			}
			buffer[bufferIndex++] = nullStr[j];
		}
	}

	if (bufferIndex > 0)
	{
		write(1, buffer, bufferIndex);
		(*i) += bufferIndex;
	}
}
