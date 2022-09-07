#include "monty.h"
/**
 * main - entry point of the program
 *
 */
int main(int ac, char **av)
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	printf("done\n");

	file_hndlr(av[1]);
	
	return (0);
}
