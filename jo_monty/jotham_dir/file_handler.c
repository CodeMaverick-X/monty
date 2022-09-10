#include "monty.h"
/**
 * open a file and read its content to a buffer
 * @filename: filename
 * Return: the buffer
 */
char *file_hndlr(char *filename)
{
	unsigned int fd;
	void *buff;
	ssize_t rd;
	struct stat st;
	off_t count;


	stat(filename, &st);
	count = st.st_size;

	buff = malloc(sizeof(char) * count);
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	rd = read(fd, buff, count);
	if (rd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (buff);


}
