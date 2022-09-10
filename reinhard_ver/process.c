#include "monty.h"
cmd_t *opc_s = NULL;
char *strdup(const char *);

/**
 * process - split the line to get the opcode and the argument
 * @stack: double pointer to stack
 * @line: line from the file
 * @line_num: line number
 * Return: o on success -1 on error
 */
int process(stack_t **stack, char *line, unsigned int line_num)
{
	size_t n = sizeof(cmd_t);
	void (*func)(stack_t **stack, unsigned int line_number);
	char *push_c;
	char *pint_c;

	pint_c = "pint";
	push_c = "push";
	opc_s = memset(malloc(sizeof(cmd_t)), 0, n);
	if (opc_s == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (-1);
	}

	opc_s->opcode = NULL;
	opc_s->n = 0;
	opc_s->line_num = line_num;

	split(line, opc_s);

	if ((strcmp(opc_s->opcode, push_c) == 0) && (opc_s->n == 0))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free(opc_s->opcode);
		free(opc_s);
		return (-1);
	}
	if ((strcmp(opc_s->opcode, pint_c) == 0) && (*stack == NULL))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		free(opc_s->opcode);
		free(opc_s);
		return (-1);
	}

	func = get_func(opc_s->opcode);
	if (!func)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opc_s->opcode);
		free(opc_s->opcode);
		free(opc_s);
		return (-1);
	}

	func(stack, line_num);

	free(opc_s->opcode);
	free(opc_s);
	return (0);
}
/**
 * split - splits the line and gets the first word
 * will impliment getting the secong word/argument soon
 *
 * @line: the line to be split
 * @ptr: pointer to a stucture that will hold the command
 * and its argument
 *
 * Return: 0
 */
int split(char *line, cmd_t *ptr)
{
	int i, j = 0;
	char opcode_a[1024];
	char arg_a[1024];
	char *push_c = "push";

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ')
			break;
	}

	while (line[i] != ' ' && line[i] != '\0')
	{
		opcode_a[j] = line[i];
		i++;
		j++;
	}
	opcode_a[j] = '\0';

	ptr->opcode = strdup(opcode_a);

	if (strcmp(ptr->opcode, push_c) == 0)
	{
		for (; line[i] != '\0'; i++)
		{
			if (line[i] != ' ')
				break;
		}
		j = 0;
		while (line[i] != '\0' && line[i] != ' ')
		{
			arg_a[j] = line[i];
			i++;
			j++;
		}

		arg_a[j] = '\0';

		ptr->n = atoi(arg_a);
	}

	return (0);
}
