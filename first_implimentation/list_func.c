#include "monty.h"
/**
 * add_nodeint - adds int n at the beggining of a doubly
 * lined list
 * @stack: double pointer to stack
 * @n: intiger to be added to the stack
 *
 * Return: null on error or the address of the new node
 */
stack_t *add_nodeint(stack_t **stack, int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (!(*stack))
	{
		*stack = new;
		return (new);
	}

	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;

	return (new);

}
/**
 * free_stack_t - frees the stack
 * @head: pointer to stack
 */
void free_stack_t(stack_t *head)
{
	if (!head)
		return;

	while (head->next != NULL)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
