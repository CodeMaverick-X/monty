#include "../monty.h"
/**
 * pall - prints all the values on the stack
 * starting from the top of the stack
 */

void pall(stack_t **stack, unsigned int line)
{

	if (*stack == NULL)
		return;

	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}

	printf("%d\n", (*stack)->n);

	return;
}



