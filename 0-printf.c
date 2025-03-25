#include "main.h"
#include "stdio.h"
#include "stdarg.h"

/**
 * _printf - mimic a printf function in C
 * @format: the given string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* move to next character afer % */
			
			if (*format == '\0')
			{
				return (-1);
			}
			else if (*format == 'c')
			{
				char current_c = va_arg(args, int);
				putchar(current_c);
				count++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (str == NULL)
				str = "(null)";

				while (*str)
				{
				putchar(*str);
				count++;
				str++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count += 1;
			}
			else /* handle invalid specifiers */
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}
		}
		else
		{
		putchar(*format);
		count++;
		}

		format++;

	}

	va_end(args);
	return (count);
}




