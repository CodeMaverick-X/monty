#include "monty.h"
/**
 * to test and compare the opcodes
 */
int process(char *line)
{
	cmd_t opc_s;
	int rt;

	rt = split(line, &opc_s);

	printf("%s\n", opc_s.opcode);

	return (0);
}

int split(char *line, cmd_t *ptr)
{
	int i, j = 0;
	char opcode_a[5];

	for (i = 0; line[i] != '\0'; i++)
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

	
	return (0);
}
