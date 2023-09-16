#include "main.h"
/**
* _puts - prints a string value  with a newline
 * @str: the string to be printed
 * Return: void
*/
int _puts(char *str)
{
    char *pointer = str;

    while (*str)
    {
        _putchar(*str++);
    }
    return (str - pointer);
}

/**
* _putchar - writes a character (c) to the standard output
 * @c: the char to be printed
 * Return: On success 1, -1 on error
*/
int _putchar(int c)
{
    static char buffer[OUTPUT_BUF_SIZE];
    static int integer;

    if (c == BUF_FLUSH || integer >= OUTPUT_BUF_SIZE)
    {
        write(1, buffer, 1);
        integer = 0;
    }
    if (c != BUF_FLUSH)
    {
        buffer[integer++] = c;
    }
    return (1);
}