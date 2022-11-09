#include<stdio.h>

const char consonants[] = {'a', 'e', 'i', 'o', 'u'};
const char vocals[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	unsigned int length = 1;

	printf("How long should the name be?\n");

	fflush(stdout);

	if (scanf_s("%i", &length) == 1) {
		printf("You want a name thats %i characters long.\n", length);
	}

	return 0;
}