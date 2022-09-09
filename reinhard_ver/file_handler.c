#include "monty.h"
/**
 * open a file and read its content to a buffer
 * @filename: filename
 * Return: the buffer
 */
char *file_hndlr(char *filename)
{
	unsigned int fd;
	void *buff = NULL;
	ssize_t rd;
	struct stat st;
	off_t count;
	int rt_s;

	rt_s = stat(filename, &st);
	if (rt_s == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		return (NULL);
	}

	count = st.st_size + 50;
	size_t n = count;
	buff = memset(malloc(sizeof(char) * count), 0, n);
	if (buff == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		return (NULL);
	}

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(buff);
		return (NULL);
	}
	
	rd = read(fd, buff, count);
	if (rd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(buff);
		return (NULL);
	}

	return (buff);


}
