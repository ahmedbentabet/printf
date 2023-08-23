#include "main.h"

/**
 * _printf - function output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					char ch = (char)va_arg(args, int);

					_putchar(ch);
					count++;
					break;
				case 's':
					print_string(va_arg(args, char *), &count);
					break;
				case 'd':
				case 'i':
					print_number(va_arg(args, int), &count);
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					_putchar('%');
					count++;
					if (*format)
					{
						_putchar(*format);
						count++;
					}
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
