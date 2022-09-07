#include "monty.h"
/**
 * to test and compare the opcodes
 * not yet completed
 */
int process(char *line)
{
	cmd_t opc_s;//define the struct for the command and argument
	int rt;

	rt = split(line, &opc_s);

	printf("%s\n", opc_s.opcode);//tests to help debug

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

	
	return (0);
}
