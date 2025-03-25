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
			format++;
			if (*format == 'c')
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
			else
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

int main() {
    int len1 = _printf("hellooo %s\n", "world");

    int len2 = _printf("Test character %%!\n", 'A');

    int len5 = _printf("Test character %!\n", 'A');

    int len3 = _printf("random number %d\n", 12888);

    int len4 = _printf("goodnight %d\n", -888);

    printf("Characters printed: %d, %d, %d, %d\n", len1, len2, len5, len4);
    return 0;
}



