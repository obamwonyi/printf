#ifndef MAIN_H

#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);

int handleSpecifier(const char *format, int numOfPrints, va_list args);

void handlesInt(const char *format, va_list args);

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#endif