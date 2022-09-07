#include "monty.h"
/**
 * open the file and perform operations
 */
int file_hndlr(char *filename)
{
	unsigned int fd;
	void *buff;
	ssize_t rd;
	size_t count = 1024;


	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	
	rd = read(fd, buff, count);

/*
	instruction_t arr[] = {
		{"push", push},
		{"pop", pop},
		{"pall", pall},
	};
*/


}
