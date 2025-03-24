#include "stdio.h"
#include "main.h"

int main() {
	int len1 = _printf("hellooo %s\n", "world");

	int len2 = _printf("Test character %c\n", 'A');

	int len3 = _printf("Test character %% sign\n");

	printf("Characters printed: %d, %d, %d\n", len1, len2, len3);
	return 0;
}