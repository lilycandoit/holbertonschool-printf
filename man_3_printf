.TH _printf 3 "March 2025" "Version 1.0" "Custom Library Manual"
.SH NAME
_printf \- mimic a printf function in C for formatted output
.SH SYNOPSIS
.B #include "main.h"
.sp
.B #include "stdio.h"
.sp
.B #include "stdarg.h"
.sp
.B #include "limits.h"
.sp
.B int _printf(const char *format, ...);
.SH DESCRIPTION
The \fB_printf\fR function is a custom implementation that produces output according to a format string. The format string is composed of zero or more directives. This implementation handles the following conversion specifiers:
.IP \(bu
\fB%c\fR \- Prints a single character.
.IP \(bu
\fB%s\fR \- Prints a string. If the string is \fBNULL\fR, it prints \fB(null)\fR.
.IP \(bu
\fB%d\fR or \fB%i\fR \- Prints a signed integer, including negative values.
.IP \(bu
\fB%%\fR \- Prints a literal percentage sign.
.PP
This function does not handle:
.IP \(bu
Buffer management.
.IP \(bu
Flag characters, field width, precision, or length modifiers.
.PP
The function writes output directly to \fBstdout\fR, the standard output stream.
.SH RETURN VALUE
Returns the total number of characters printed (excluding the null byte used to terminate strings). If the \fBformat\fR string is \fBNULL\fR, or if an error occurs, it returns \fB-1\fR.
.SH EXAMPLES
.B #include "main.h"
.sp
.B int main() {
.B     _printf("Character: %c\\n", 'A');
.B     _printf("String: %s\\n", "Hello, World!");
.B     _printf("Integer: %d\\n", 42);
.B     _printf("Percent sign: %%\\n");
.B     return 0;
.B }
.SH SEE ALSO
\fBprintf\fR(3)
