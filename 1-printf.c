#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _putchar -writes a character to stdout
 * @c: the character to write
 *
 * Return: on success 1. on error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _printf - produces output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int chars_printed = 0;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* move past the '%' */
			
			switch (*format)
			{
				case 'c':
					chars_printed += _putchar(va_arg(args, int));
					break;
				case 's':
					chars_printed += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
					break;
				case '%':
					chars_printed += _putchar('%');
					break;
				default:
					chars_printed += _putchar('%');
					chars_printed += _putchar(*format);
			}			
		}
		else
			chars_printed += _putchar(*format);

		format++; /* move to next character */
	}

	va_end(args);
	return (chars_printed);
}
