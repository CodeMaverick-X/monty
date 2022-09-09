#include "monty.h"
/**
 * main - entry point of the program
 *
 */
int main(int ac, char **av)
{
	char *file = NULL;
	int rt_m;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = file_hndlr(av[1]);
	if (file == NULL)
		exit(EXIT_FAILURE);

	printf("%s", file);

	rt_m = helper(file);
	if (rt_m == -1)
	{
		free(file);
		exit(EXIT_FAILURE);
	}

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
	int rt;

	line_num = 1;
	str = strtok(file, "\n");
	while(str != NULL)
	{
		rt = process(stack, str, line_num);
		if (rt == -1)
		{
			return (-1);
		}
		str = strtok(NULL, "\n");
		line_num++;

	}

	return (0);
}
