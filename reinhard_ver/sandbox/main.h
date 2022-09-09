#ifndef main_a
#define main_a
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cmd_s
{
	int n;
} cmd_t;

extern cmd_t *ptr;
void push(char *line);

#endif
