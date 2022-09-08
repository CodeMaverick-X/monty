#include "../monty.h"
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
	int characters, words, lines, line;
	char word[] = "push";
	FILE *fptr;
	char ch;
	char *s;
	char *str;
	struct stat buff;
	char *file = argv[1];
	char *file_buff;
	int i = 0;
	stack_t *stack;

	stack->n = 8;
	push(&stack, 2);
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

	//printf("%ld\n", size);

	file_buff = malloc(sizeof(char) * size);
	if (!file_buff)
	{
		perror("Memory Allocation");
	}
	line = 1;
	/*while(fgets(file_buff, size, fptr) != NULL)
	{
		//if (file_buff == "push")
		       //printf("%s\n", file_buff);
		str = file_buff;
		s = loop_through_string(&str, line);
		//for (i = 0; *str != '\0' && i < size; str++)
		//{
		//	s[i] = *file_buff;
		//	i++;
			//printf("%s: %s", str, s);
		//}
		line++;
	
	}*/
	

	//Remember to use strdup() and pass it to another func
	//fclose(fptr);

	//printf("%s\n", str);

	/*file_buff[0] = '\0';
	file_buff[size - 1] = ~'\0';
	eof = fgets(file_buff, size, fptr);
	if (eof == NULL)
	{		
		perror("File data");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", file_buff);*/
	/*while ((ch = fgetc(fptr)) != EOF)
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

	file_buff[i + 1] = '\0';

	s = _strtok(file_buff, " ");
	if (strcmp(s, word))
		printf("found!\n")
	while (s)
	{
		printf("%s\n", s);
		//if (strcmp(s, word))
			//printf("found\n");

		i++;
	}*/
	return (0);
}
