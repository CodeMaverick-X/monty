#ifndef __MONTY__
#define __MONTY__
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct command_s - cointainer for command/opcode
 * @opcode: the opcode
 * @n: the argumeent
 * @line_num: line number
 *
 * Description: store the opcode its line number
 * and its argument to allow ease of access
 * by other functions and files
 */
typedef struct command_s
{
	char *opcode;
	int n;
	unsigned int line_num;
} cmd_t;

extern cmd_t *opc_s;

/* more functions go underneat here */
char *file_hndlr(char *filename);
int helper(char *file);
int process(stack_t **stack, char *line, unsigned int line_num);
int split(char *line, cmd_t *ptr);
void (*get_func(char *opcode_r))(stack_t **stack, unsigned int line_number);

/* opcode funcions go here */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);

/* list functions go here */
stack_t *add_nodeint(stack_t **stack, int n);
void free_stack_t(stack_t *head);

#endif
