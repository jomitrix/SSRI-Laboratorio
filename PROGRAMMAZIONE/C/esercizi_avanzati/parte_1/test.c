// C program to demonstrate
// example of tolower() function.
#include <ctype.h>
#include <stdio.h>

int main()
{

	// convert 'M' to lowercase
	char ch = tolower('3');

	// Printing the lowercase letter
	printf("%c %d", ch, isalpha(ch));

	return 0;
}
