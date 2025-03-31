# **_printf**

## **Description**
**_printf** is a custom implementation of the standard C `printf` function, designed to format and print output to the standard output stream.

## **Prototype**
```c
int _printf(const char *format, ...);
```

## **Supported Format Specifiers**
This implementation supports the following conversion specifiers:
- `%c` - Prints a single character
- `%s` - Prints a string
- `%d` - Prints a decimal integer
- `%i` - Prints an integer
- `%%` - Prints a percent sign

### **Limitations**
This implementation does **not** support:
- Buffer management
- Flag characters, field width, precision, or length modifiers

## **Return Value**
- Returns the total number of characters printed (excluding the null byte used to terminate strings).
- Returns `-1` if an error occurs or if the format string is `NULL`.

## **Installation**
1. Clone the repository:
   ```sh
   git clone https://github.com/lilycandoit/holbertonschool-printf.git
   ```
2. Navigate to the project directory:
   ```sh
   cd holbertonschool-printf
   ```
3. Compile the program:
   ```sh
   gcc -Wall -Werror -Wextra -pedantic *.c -o printf
   ```

## **Usage**
```c
#include "main.h"

int main() {
    _printf("Character: %c\n", 'A');
    _printf("String: %s\n", "Hello, World!");
    _printf("Integer: %d\n", 42);
    _printf("Percent sign: %%\n");
    return 0;
}
```

### **Expected Output**
```
Character: A
String: Hello, World!
Integer: 42
Percent sign: %
```

## **Running the Program**
After compiling, execute the program with:
```sh
./printf
```

## **Contributors**
- **Lily**
- **Xiaoling**
- **Wawa**

