#include "../monty.h"
/**
 * add_dnode_at_top_stack - program adds a doubly linked list
 * at the top of the stack
 * @n: new data to add
 *
 * Return: pointer to new node
 */
stack_t *top = NULL;

stack_t *add_dnode_at_top_stack(int n, unsigned int line)
{
	stack_t *new;

	if (!n)
	{
		printf("L%d: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}	

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;

	/*if (top == NULL)
	{
		new->next = top;
		top = new;
		return (new);	
	}*/

	new->next = top;
	top = new;

	return (new);
}
