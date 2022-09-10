#include "../monty.h"
/**
 * loop_through_string - program print each word in a line
 * with the help of _strtok function
 * @str: string to loop through
 * @line: line where the program is currently at in a file
 *
 * Return: pointer to string
 */

void push(stack_t **stack, unsigned int line)
{
	stack_t *s = *stack;
	add_dnode_at_top_stack(s->n, line);
	/*string = _strtok(*str, " ");
	while (string)
	{
		string = _strtok(NULL, " ");
		//printf("line %d: %s\n", line, string);
		if (string == "push" || string == "pall")
		{
			printf("%s", string);
		}
		return (string);
	}

	//printf("%d: %s\n", line, string);

	return (string);*/
}
