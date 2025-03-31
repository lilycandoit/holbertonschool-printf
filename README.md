# **_printf**

**_printf** - A printf function in C for formatted output.

## **SYNOPSIS**
```c
#include "main.h"
#include "stdio.h"
#include "stdarg.h"
#include "limits.h"

##PROTOTYPE

int _printf(const char *format, ...);

##DESCRIPTION
This implementation handles the following conversion specifiers:

This function does not handle:

Buffer management.
Flag characters, field width, precision, or length modifiers.
The function writes output directly to stdout, the standard output stream.

##RETURN VALUE

Returns the total number of characters printed (excluding the null byte used to terminate strings). If the format string is **NULL** , or if an error occurs, it returns -1 .

##INSTALLATION

- Clone the repository using: git clone ~~https://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@github.com/lilycandoit/holbertonschool-printf.git~~

- Configure Git

##EXAMPLES

#include "main.h"

int main() {
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Integer: %d\n", 42);
    _printf("Percent sign: %%\n");
    return 0;
}

###Expected Output:

Character: A
String: Hello, World!
Integer: 42
Percent sign: %

##COMPILING AND EXECUTING

gcc -Wall -Werror -Wextra -pedantic *.c -o printf

###Run the executable:
./printf

##CONTRIBUTORS
- Lily
- Xiaoling
- Wawa