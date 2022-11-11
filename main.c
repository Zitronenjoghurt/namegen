#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct
{
	int success;
	char* string;
} GeneratorResult;

GeneratorResult generateName(int);

const char vocals[5] = {'a', 'e', 'i', 'o', 'u'};
const char consonants[20] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z' };

int main()
{
	srand((unsigned int)time(NULL));

	printf("=====[NAME GENERATOR]=====\nHow long should the name be?\n");
	fflush(stdout);

	int length = 1;
	if (scanf_s("%i", &length) == 1) 
	{
		GeneratorResult genRes = generateName(length);

		if (genRes.success == 1)
		{
			printf("\nSuccessfully generated:\n%s\n", genRes.string);
		}
		else
		{
			printf("\n%s\n", genRes.string);
		}
	}

	printf("=====[NAME GENERATOR]=====");

	return 0;
}

GeneratorResult generateName(int length)
{
	char* result = calloc((size_t)(length + 1), sizeof(char));

	if (result == NULL)
	{
		GeneratorResult r = { 0, "ERROR ALLOCATING MEMORY" };
		return r;
	}
	
	int random = 0;
	for (int i = 0; i < length; i++)
	{
		if (i % 2 == 0)
		{
			random = rand() % (sizeof(vocals) / sizeof(vocals[0]));
			result[i] = vocals[random];
		}
		else
		{
			random = rand() % (sizeof(consonants) / sizeof(consonants[0]));
			result[i] = consonants[random];
		}
	}

	result[length] = '\0';

	GeneratorResult r = { 1, result };
	return r;
}