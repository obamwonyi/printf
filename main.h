#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int _printf(const char *format, ...);
void print_binary(long num, int *i);
void print_string(va_list ap, int *i);
void print_origin(char c, int *i);
void print_char(va_list ap, int *i);
void print_int(va_list ap, int *i);
void print_unsigned_int(va_list ap, int *i);
void print_octal(va_list ap, int *i);
void print_hex_lower(va_list ap, int *i);
void print_hex_upper(va_list ap, int *i);
#endif
