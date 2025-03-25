#include "main.h"
#include "stdio.h"
#include "stdarg.h"

/**
* print_char - to print %c
* @count: the number of character printed
* Return: void
*/
void print_char(va_list args, int *count)
{
	char current_c = va_arg(args, int);

	putchar(current_c);
	(*count)++;
}

/**
* print_str - to print %s
* @count: the number of character printed
* Return: void
*/
void print_str(va_list args, int *count)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	str = "(null)";

	while (*str)
	{
	putchar(*str);
	(*count)++;
	str++;
	}
}
/**
* print_char - to print %%
* @count: the number of character printed
* Return: void
*/
void print_percent(int *count)
{
	putchar('%');
	(*count)++;
}

/**
 * _printf - mimic a printf function in C
 * @format: the given string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /* move to next character afer % */

			if (*format == '\0')
				return (-1);

			else if (*format == 'c')
				print_char(args, &count);

			else if (*format == 's')
				print_str(args, &count);

			else if (*format == '%')
				print_percent(&count);

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





