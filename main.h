#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int _putchar(char c);
void print_number(int n);
void print_string(const char *str, int *count);
int _printf(const char *format, ...);

#endif /* MAIN_H */