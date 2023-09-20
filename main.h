#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
int _printf(const char *format, ...);
void print_binary(int num, int *i);
void print_special_char(char c, int *i);
#endif
