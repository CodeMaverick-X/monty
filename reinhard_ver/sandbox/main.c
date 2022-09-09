#include "main.h"
cmd_t *ptr = NULL;

int main(void)
{
	cmd_t *ptr = malloc(sizeof(cmd_t));
	ptr->n = 5;
	push("line");

	return (0);
	
}
