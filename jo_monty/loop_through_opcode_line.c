#include "../monty.h"
/**
 * loop_through_string - program print each word in a line
 * with the help of _strtok function
 * @str: string to loop through
 * @line: line where the program is currently at in a file
 *
 * Return: pointer to string
 */

char *loop_through_string(char **str, int line)
{
	char *string;
	int num;
	//unsigned int i = 0;
	
	//printf("%s\n", *str);
	if (!*str)
		perror("Empty line");

	string = _strtok(*str, " ");
	while (string)
	{
		string = _strtok(NULL, " ");
		printf("line %d: %s\n", line, string);
		if (string == "push" || string == "pall")
		{
			num = string++;
			printf("%i", num);
		}
		return (string);
	}

	//printf("%d: %s\n", line, string);

	return (string);
}
