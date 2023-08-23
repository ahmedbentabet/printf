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
		print_number(m / 10, count);

	_putchar((m % 10) + '0');
	(*count)++;
}

/**
 * print_binary - Prints the binary representation of an unsigned integer.
 * @n: The unsigned integer to be printed in binary.
 * @count: Pointer to the character count.
 */
void print_binary(unsigned int n, int *count)
{
	int d = count_digits(n);
	int i = 0;
	char *b_str = (char *)malloc(d);

	if (!b_str)
		return;
	while (n > 0)
	{
		b_str[i] = (n % 2) + '0';
		n /= 2;
		i++;
	}
	if (i == 0)
		b_str[i++] = '0';
	b_str[i] = '\0';
	for (i = i - 1; i >= 0; i--)
	{
		_putchar(b_str[i]);
		(*count)++;
	}
	free(b_str);
}

/**
 * count_digits - Counts the number of digits in an integer.
 * @n: The integer for which to count digits.
 *
 * Return: The number of digits in the integer.
 */
int count_digits(int n)
{
	int digits = 0;

	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}
