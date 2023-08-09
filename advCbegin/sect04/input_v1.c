#include <stdio.h>

int main(void) {
	char str[100];
	int i;

	printf("Enter a integer and a string:\n");

	scanf("%d %s", &i, str);

	printf("You entered ‘%d’ and ‘%s’.\n", i, str);

	return 0;
}

/*

$ ./out/input_v1
Enter a integer and a string:
1
One
You entered ‘1’ and ‘One’.

*/
