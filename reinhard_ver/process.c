#include "monty.h"
/**
 * to test and compare the opcodes
 * not yet completed
 */
int process(char *line)
{
	cmd_t *opc_s = NULL;//define the struct for the command and argument
	int rt;

	opc_s = malloc(sizeof(cmd_t));
	opc_s->opcode = NULL;
	opc_s->n = 0;	

	rt = split(line, opc_s);

	printf("^^^^%s\n", opc_s->opcode);//tests to help debug
	printf("^^^^%d\n", opc_s->n);

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
	char opcode_a[5];
	char arg_a[5];
	char *push_c;

	push_c = "push";
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

	ptr->opcode = opcode_a;
	//debugging
	printf(">>>>>>%s\n", ptr->opcode);

	if (strcmp(ptr->opcode, push_c) == 0);
	{
		printf("equalilty found\n");
		for (; line[i] != '\0'; i++)
		{
			if (line[i] != ' ')
				break;
		}
		j = 0;
		while (line[i] != ' ')
		{
			arg_a[j] = line[i];
			i++;
			j++;
		}
		
		arg_a[j] = '\0';

		ptr->n = atoi(arg_a);
		printf(">>>>>>%d\n", ptr->n);
	}


	
	return (0);
}
