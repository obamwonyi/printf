#ifndef MAIN_H

#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int _printf(const char *format, ...);

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#endif