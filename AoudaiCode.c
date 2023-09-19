void print_string(va_list ap, int *i)
{
	char *str;
	char c;
	int j;

	str = va_arg(ap, char *);
	if (str != NULL)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			c = str[j];
			write(1, &c, 1);
			*i = *i + 1;
		}
	}
}


void print_origin(char c, int *i)
{
	write(1, &c, 1);
	*i = *i + 1;
}