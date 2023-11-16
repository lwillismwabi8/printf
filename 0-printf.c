#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string containing conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr;

	va_start(args, format);
	for (ptr = format; ptr && *ptr; ptr++)
	{
		if (*ptr != '%')
		{
			printf("%c", *ptr);
			count++;
		}
		else
		{
			switch (*(++ptr))
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += printf("%%");
					break;
				default:
					count += printf("%%%c", *ptr);
					break;
			}
		}
	}
	va_end(args);
	return (count);
}
