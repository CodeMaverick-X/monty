#include "monty.h"
/**
 * main - read monty scripting file
 * @argv: array of arguments
 * @argc: number of arguments
 *
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	long int size;
	int characters, words, lines;
	char word[] = "push";
	FILE *fptr;
	char ch;
	char *s;
	struct stat buff;
	char *file = argv[1];
	char *file_buff;
 	char *fget;
	int i = 0;

	if (argc != 2)
		perror("fopen");

	file = argv[1];
	fptr = fopen(file, "r");
	if (!fptr)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	characters = words = lines = 0;

	if (stat(file, &buff) == -1);
	{
		perror("stat");
	}
	size = buff.st_size;

	printf("%ld\n", size);

	file_buff = malloc(sizeof(char) * size);
	if (!file_buff)
	{
		perror("Memory Allocation");
	}

	while ((ch = fgetc(fptr)) != EOF)
	{

		if (ch == '\n' || ch == '\0')
			lines++;
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
		{
			words++;
		}

		characters++;

		file_buff[i] = ch;
		i++;
	}

	s = _strtok(file_buff, " ");
	if (strcmp(s, word))
		printf("found!\n");
	while (s)
	{
		printf("%s\n", s);
		if (strcmp(s, word))
			printf("found\n");
		s = _strtok(NULL, " ");		
	}
	return (0);
}
