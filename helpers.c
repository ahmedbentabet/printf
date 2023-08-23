#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string and updates the character count.
 * @str: The string to be printed.
 * @count: Pointer to the character count.
 */
void print_string(const char *str, int *count)
{
	while (*str)
	{
		_putchar(*str);
		str++;
		(*count)++;
	}
}

/**
 * print_number - Prints an integer and updates the character count.
 * @n: The integer to be printed.
 * @count: Pointer to the character count.
 */
void print_number(int n, int *count)
{
	int m = n;

	if (n < 0)
	{
		_putchar('-');
		m = -n;
	}

	if (m >= 10)
		print_number(m / 10 , count);

	_putchar((m % 10) + '0');
	(*count)++;
}
