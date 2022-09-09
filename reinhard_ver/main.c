#include "monty.h"
/**
 * main - entry point of the program
 *
 */
int main(int ac, char **av)
{
	char *file = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = file_hndlr(av[1]);

	printf("%s", file);

	helper(file);

	free(file);
	
	return (0);
}
/**
 * parse - execute the process function on each line
 * of the file
 *
 */
int helper(char *file)
{
	stack_t *stack = NULL;
	char *str = NULL;
	unsigned int line_num;

	line_num = 1;
	str = strtok(file, "\n");
	while(str != NULL)
	{
		process(stack, str, line_num);
		str = strtok(NULL, "\n");
		line_num++;

	}

	return (0);
}
