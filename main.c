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
	/* This will set a random seed for the rand() function based on the current time */
	srand((unsigned int)time(NULL));

	printf("=====[NAME GENERATOR]=====\nHow long should the name be?\n");
	fflush(stdout);

	/* 
	 * The input would be a number and ENTER for confirmation, so its actually 2 inputs. 
	 * We have to catch the \n (from hitting ENTER) so the input stream is cleared.
	 * If we don't catch the ENTER here, the getchar later at 'Press [ENTER] to exit...' will think we already hit ENTER even tho we didn't.
	 */
	char catchEnter = 0;
	
	int length = 1;
	if (scanf_s("%i%c", &length, &catchEnter, 1) == 2) 
	{
		GeneratorResult genRes = generateName(length);

		if (genRes.success == 1)
		{
			printf("\nSuccessfully generated:\n%s", genRes.string);
		}
		else
		{
			printf("\n%s", genRes.string);
		}
	}

	printf("\n\nPress [ENTER] to exit...");

	fflush(stdout);
	char ch = getchar();

	printf("\n=====[NAME GENERATOR]=====");

	return 0;
}

GeneratorResult generateName(int length)
{
	/* Allocating length + 1 char's because you will need to push an \0 at the end to tell when the string ends. */
	char* result = calloc((size_t)(length + 1), sizeof(char));

	/* Catching possible null pointer exception if there was an error while allocating memory for the result array. */
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

	/* Uppercasing the first letter (this only works because I know there can only be basic ASCII letters in result) */
	result[0] = result[0] - 32;

	/* Putting 0 at the end of the array to indicate the end of the string. */
	result[length] = '\0';

	GeneratorResult r = { 1, result };
	return r;
}