#include "main.h"
#include "stdio.h"
#include "stdarg.h"
#include "limits.h"

/**
* print_num - to handle %d and %i
* @num: the integer passed in
* @count: a pointer to an int to track the number of characters printed
* Return: void
*/

void print_num(int num, int *count)
{
	if (num == INT_MIN)
	{
		char *min_str = "-2147483648";

		while (*min_str)
		{
			putchar(*min_str);
			(*count)++;
			min_str++;
		}
		return;
	}

	if (num < 0)
	{
		putchar('-');
		(*count)++;
		num  = -num;
		/* need to convert to positive number */
		/* to work with putchar later */
	}

	if (num / 10) /* recursion to print all digits */
		print_num(num / 10, count);

	putchar((num % 10) + '0'); /* last digit */

	(*count)++;
	/* increase the integer (value) stored at pointer */
}

/**
* print_char - to print %c
* @args: the arguments stored in va_list
* @count: a pointer to an int to track the number of characters printed
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
* @args: the arguments stored in va_list
* @count: a pointer to an int to track the number of characters printed
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
* print_percent - to print %%
* @count: a pointer to an int to track the number of characters printed
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
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				print_num(num, &count);
			}
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

int main()
{
	_printf("hello %s\n", "world", 1, 2, 3, 4);
	return (0);
}
