#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

typedef struct type_format
{
    char c;
    int (*f)(va_list args, int *);
} tf;

// Recursive helper function for printing digits
void print_digits(int num, int *count)
{
    if (num / 10)
        print_digits(num / 10, count);

    putchar((num % 10) + '0');
    (*count)++;
}

// Integer type
int print_num(va_list args, int *count)
{
    int num = va_arg(args, int);
    // Handle minimum integer value separately
    if (num == -2147483648)
    {
        const char *min_str = "-2147483648";
        while (*min_str)
        {
            putchar(*min_str);
            (*count)++;
            min_str++;
        }
        return *count;
    }

    // Handle negative numbers
    if (num < 0)
    {
        putchar('-');
        (*count)++;
        num = -num;
    }

    // handle the rest cases
    print_digits(num, count);

    return *count;
}

// Char type
int print_char(va_list args, int *count)
{
    char current_c = va_arg(args, int);
    putchar(current_c);
    (*count)++;

    return *count;
}

// String type
int print_str(va_list args, int *count)
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

    return *count;
}

int print_percent(va_list args, int *count)
{
    (void)args;  // ignore unused
    putchar('%');
    (*count)++;
    return *count;
}

// Get the correct type
int (*get_type(char c))(va_list, int *)
{
    tf types_format[] =
    {
        {'c', print_char},
        {'s', print_str},
        {'%', print_percent},
        {'d', print_num},
        {'i', print_num},
        {'\0', NULL}
    };

    int i = 0;
    while (types_format[i].c != '\0')
    {
        if (types_format[i].c == c)
        {
            return types_format[i].f;
        }
        i++;
    }

    return NULL;
}

// Main _printf function
int _printf(const char * const format, ...)
{
    va_list args;
    int i = 0, count = 0;
    int (*f)(va_list, int *);// function pointer

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%' && format[i+1])
        {
            i++;
            f = get_type(format[i]); //to get the right function type
            if (f)
                count = f(args, &count);
            else /* handle invalid specifiers */
            {
                putchar('%');
                putchar(format[i]);
                count += 2;
            }
        }
        else {
            putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
	_printf("hello %s\n", "world", 1, 2, 3, 4);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}
