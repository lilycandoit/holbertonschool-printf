NAME
_printf - a printf function in C for formatted output
SYNOPSIS
#include "main.h"
#include "stdio.h"
#include "stdarg.h"
#include "limits.h"
Prototype
int _printf(const char *format, ...);
DESCRIPTION
This implementation handles the following conversion specifiers:
%c - Prints a single character.
%s - Prints a string. If the string is NULL, it prints (null).
B% or %i - Prints a signed integer, including negative values.
%%- Prints a literal percentage sign.
This function does not handle:
Buffer management.
Flag characters, field width, precision, or length modifiers.
The function writes output directly to stdout, the standard output stream.
RETURN VALUE
Returns the total number of characters printed (excluding the null byte used to terminate strings). If the format string is BNULL, or if an error occurs, it returns B-1.
EXAMPLES
#include "main.h"
int main() {
_printf("Character: %c\\n", 'A');
_printf("String: %s\\n", "Hello, World!");
_printf("Integer: %d\\n", 42);
_printf("Percent sign: %%\\n");
return 0;
}
SEE ALSO
printf(3)