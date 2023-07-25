/**
 * To do add comments for all the structs
 * with proper explanation
 */
#ifndef PRINTF_MAIN_H
#define PRINTF_MAIN_H

/**
 * including the various standard library
 * needed for this project
 */

/**
 * (1) Standard input/output library
 */
#include <stdio.h>

/**
 * (2) Unix Standard (for system calls)
 */
#include <unistd.h>

/**
 * (3) Limits, macros for handling minimum and maximum values of integral
 * data types(integer kind of data types like int, long and so on) across
 * platforms .
 *
 */
#include <limits.h>

/**
 * Standard Library , for memory allocation and management
 */
#include <stdlib.h>

/**
 * standard arguments , for variadic functions
 */
#include <stdarg.h>


/**
 * constants
 */
#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2


typedef struct parameters
{
    /**
     * unsigned bit
     */
    unsigned int unsign : 1;
    /**
     * various flags  created as bit-field member
     */
    unsigned int hashtagFlag : 1;
    unsigned int spaceFlag : 1;
    unsigned int zeroFlag : 1;
    unsigned int minusFlag : 1;
    unsigned int plusFlag : 1;

    unsigned int hModifier : 1;
    unsigned int lModifier : 1;

    unsigned int width;
    unsigned int precision;
} paramsT;

/**
 *
 */
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, paramsT);
} specifierT;

/** _put.c module */
int _puts(char *str);
int _putchar(int c);

/** printFunctions.c module */
int printfChar(va_list argPointer, paramsT *parameters);
int printfInt(va_list argPointer, paramsT *parameters);
int printfString(va_list argPointer, paramsT *parameters);
int printfPercent(va_list argPointer, paramsT *parameters);
int printfS(va_list argPointer, paramsT *parameters);

/** number.c module */
char printAddress(va_list argPointer, paramsT *parameters);
char *convert(long int num, int base, int flags, paramsT *parameters);
char printUnsigned(va_list argPointer, paramsT *parameters);

/** specifier.c module */
int (*getSpecifier(char *s)) (va_list argPointer, paramsT *parameters);
int getPrintFunction (char *s, va_list argPointer, paramsT *parameters);
int getFlag(char *s, paramsT *parameters);
int getModifier(char *s, paramsT *parameters);
int *getWidth(char *s, paramsT *parameters, va_list argPointer);

/** convertNumber.c module */
int printhex(va_list argPointer, paramsT *parameters);
int printHex(va_list argPointer, paramsT *parameters);
int printBinary(va_list argPointer, paramsT *parameters);
int printOctal(va_list argPointer, paramsT *parameters);

/** simplePrinters.c module */
int printFromTo(char *begin, char *end, char *exception);
int printRev(va_list argPointer, paramsT *parameters);
int printRot13(va_list argPointer, paramsT *parameters);

/** printNumbers.c module */
int _isdigit(int c);
int _strlen(char *s);
int printNumber(char *string, paramsT *parameters);
int printNumberRightShift(char *string, paramsT *parameters);
int printNumberLeftShift(char *string, paramsT *parameters);

/** params.c module */
void initParams(paramsT *parameters, va_list argPointer);

/** stringField.c module */
char *getPrecision(char *p, paramsT *parameters, va_list argPointer);

/** _printf.c module */
int _printf(const char *format, ...);


#endif //PRINTF_MAIN_H
