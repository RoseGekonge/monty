#ifndef _MONTY_H_
#define _MONTY_H_
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

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

char *get_data_mode(void);
char **get_lines(void);
void exit_program(int status);
void clean_up_program(void);

/* Opcode handlers */

void mty_op_push(stack_t **stack, unsigned int line_number);
void mty_op_pall(stack_t **stack, unsigned int line_number);
void mty_op_pint(stack_t **stack, unsigned int line_number);
void mty_op_pop(stack_t **stack, unsigned int line_number);
void mty_op_swap(stack_t **stack, unsigned int line_number);
void mty_op_add(stack_t **stack, unsigned int line_number);
void mty_op_nop(stack_t **stack, unsigned int line_number);
void mty_op_sub(stack_t **stack, unsigned int line_number);
void mty_op_div(stack_t **stack, unsigned int line_number);
void mty_op_mul(stack_t **stack, unsigned int line_number);
void mty_op_mod(stack_t **stack, unsigned int line_number);
void mty_op_pchar(stack_t **stack, unsigned int line_number);
void mty_op_pstr(stack_t **stack, unsigned int line_number);
void mty_op_rotl(stack_t **stack, unsigned int line_number);
void mty_op_rotr(stack_t **stack, unsigned int line_number);
void mty_op_stack(stack_t **stack, unsigned int line_number);
void mty_op_queue(stack_t **stack, unsigned int line_number);

/**
 * enum Date_Format_Modes - The data format modes for this program.
 * @DF_LIFO: The data format code for a LIFO structure (like a stack)
 * @DF_FIFO: The data format code for a FIFO structure (like a queue)
 */
enum Date_Format_Modes
{
	/* The data format code for a LIFO structure (like a stack) */
	DF_LIFO,
	/* The data format code for a FIFO structure (like a queue) */
	DF_FIFO
};

#endif
