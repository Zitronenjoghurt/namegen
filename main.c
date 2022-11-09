#include<stdio.h>

const char vocals[5] = {'a', 'e', 'i', 'o', 'u'};
const char consonants[20] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

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