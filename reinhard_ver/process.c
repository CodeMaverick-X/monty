#include "monty.h"
cmd_t *opc_s = NULL;//pointer to struct

/**
 * to test and compare the opcodes
 * not yet completed
 */
int process(stack_t *stack, char *line, unsigned int line_num)
{
	size_t n = sizeof(cmd_t);
	void (*func)(stack_t **stack, unsigned int line_number);

	opc_s = memset(malloc(sizeof(cmd_t)), 0, n);

	opc_s->opcode = NULL;
	opc_s->n = 0;
	opc_s->line_num = line_num;	

	split(line, opc_s);

	func = get_func(opc_s->opcode);
	if (!func)
	{
		printf("error, file not found in line %u\n", line_num);
		free(opc_s->opcode);
		free(opc_s);
		return (-1);
	}

	func(&stack, line_num);
	


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

	for (i = 0; line[i] != '\0'; i++)//to help ignore empty spaces at the front
	{
		if (line[i] != ' ')
			break;
	}

	while (line[i] != ' ')
	{
		opcode_a[j] = line[i];
		i++;
		j++;
	}
	opcode_a[j] = '\0';

	ptr->opcode = strdup(opcode_a);

	if (strcmp(ptr->opcode, push_c) == 0);
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
