#include "monty.h"
/**
 * main - entry point of the program
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success or exit failure on error
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
 * helper - uses strtok to share the fike into lines
 * and run the process function on them individually
 * @file: pointer to buffer contailing the copied
 * file
 * Return: -1 on error and 0 on success
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
	while (str != NULL)
	{
		rt = process(&stack, str, line_num);
		if (rt == -1)
		{
			free_stack_t(stack);
			return (-1);
		}
		str = strtok(NULL, "\n");
		line_num++;

	}

	free_stack_t(stack);
	return (0);
}
