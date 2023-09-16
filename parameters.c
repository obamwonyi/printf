#include "main.h"
/**
* initParams - clears struct fields and reset buffer
 * $parameters: struct parameters
 * @argPointer: the argument pointer
 * Return: void(none)
*/
void initParams(paramsT *parameters, va_list argPointer)
{
    parameters->minusFlag = 0;
    parameters->hashtagFlag = 0;
    parameters->zeroFlag = 0;
    parameters->spaceFlag = 0;
    parameters->plusFlag = 0;

    parameters->unsign = 0;

    parameters->width = 0;
    parameters->precision = UNIT_MAX;

    parameters->hModifier = 0;
    parameters->lModifier = 0;

    (void)argPointer;
}