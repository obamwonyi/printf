#include "main.h"

/**
* _printf - a replica of the stdio function printf()
 * @format : the format specifier
 * Return: number of the bytes that was printed.
*/
int _printf(const char *format, ...)
{
    int sum = 0;
    va_list argPointer;
    char *p, *begin;
    paramsT parameters = PARAMS_INIT;

    va_start(argPointer, format);

    if (!format || ((format[0] == '%') && !format[1]))
    {
        return (-1);
    }
    if (format[0] == '%' && format[1] == ' ' && !format[2])
    {
        return  (-1);
    }

    for (p = (char *)format; *p; p++)
    {
        initParams(&parameters, argPointer);
        if (*p != '%')
        {
            sum += _putchar(*p);
            continue;
        }
        begin = p;
        p++;

        while(getFlag(p, &parameters))
        {
            p++;
        }
        p = getWidth(p, *parameters, argPointer);
        p = getPrecision(p, &parameters, argPointer);
        if (!getSpecifier(p))
        {
            sum += printFromTo(begin, p,
                               ((parameters.hModifier || parameters.lModifier) ? p - 1 : 0))
        } else
        {
            sum += getPrintFunction(p, argPointer, &parameters);
        }
        _putchar(BUF_FLUSH);
        va_end(argPointer);
        return  (sum);
    }
}