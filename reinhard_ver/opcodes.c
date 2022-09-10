#include "monty.h"
/**
 * push - pushes arg to the stack with the hrlp
 * of add_nodeint func
 * @stack: double pointer to stack
 * @line_number: line number of command
 */
void push(stack_t **stack, unsigned int line_number)
{
	int num;
	(void)line_number;
	num = opc_s->n;

	add_nodeint(stack, num);


}

/**
 * pall - print all intigers in the stack
 * @stack: double pointer to stack
 * @line_number: line number of command
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
