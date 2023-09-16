#include "main.h"
/**
* getSpecifier - finds the function to handle the format specifier given
 * @s: the format string passed
 * Return: bytes printed
*/
int (*getSpecifier(char *s))(va_list argPointer, paramsT *parameters)
{
    specifierT specifiers[] =
            {
                    {"c", printChar},
                    {"d", printInt},
                    {"i",printInt},
                    {"s",printString},
                    {"%",printPercent},
                    {"b",printBinary},
                    {"o",printOctal},
                    {"u",printUnsigned},
                    {"x",printhex},
                    {"X",printHex},
                    {"p",printAddress},
                    {"s",printS},
                    {NULL,NULL}
            };
    int integer = 0;

    while (specifiers[integer].specifier)
    {
        if (*s == specifiers[integer].specifier[0])
        {
            return (specifiers[i].f);
        }
        integer++;
    }

    return (NULL);
}

/**
* getPrintFunction - finds the format function
 * @s: the format string
 * @argPointer: argument pointer
 * @parameter: the parameters for the struct
 * Return: the bytes printed
*/
int getPrintFunction(char *s, va_list argPointer, paramsT *parameters)
{
    int (*f)(va_list, paramsT *) = getSpecifier(s);

    if (f)
    {
        return (f(argPointer,parameters));
    }
    return (0);
}

/**
* getFlag - finds the function for the particular flag
 * @s: the format string
 * @parameters: the parameters of the struct
 * Return: boolean representation of flag validity
*/
int getFlag(char *s, paramsT *parameters)
{
    int integer = 0;

    switch (*s) {
        case ' ':
            integer = parameters->spaceFlag = 1;
            break;
        case '+':
            integer = parameters->plusFlag = 1;
            break;
        case '%':
            integer = parameters->hashtagFlag = 1;
            break;
        case '-':
            integer = parameters->minusFlag = 1;
            break;
        default:
            integer = parameters->zeroFlag = 1;
            break;
    }

    return (integer);
}

/**
* getModifier - find modifier function
 * @s: the format string
 * @parameters: the parameters struct
 * Return: if modifier was valid
*/
int getModifier(char *s, paramsT *parameters)
{
    int integer = 0;

    switch (*s) {
        case 'h':
            integer = parameters->hModifier = 1;
            break;
        default:
            integer = parameters->lModifier = 1;
            break;
    }

    return (integer);
}

/**
* getWidth - gets width from the format string
 * @s: the format string
 * @parameters: the parameters struct
 * @argPointer: the argument pointer
 * Return: new pointer
*/
char *getWidth(char *s, paramsT *parameters, va_list argPointer)
{
    int d = 0;

    if (*s == '*')
    {
        d = va_arg(argPointer, int);
        s++;
    } else
    {
        while (_isdigit(*s))
        {
            d = d * 10 + (*s++ - '0');
        }

        parameters->width = d;
        return (s);
    }
}

/**
*
*/