#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

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

typedef void (*inst_fun)(stack_t **stack, unsigned int line_number);

inst_fun get_opcode_func(char *str);
void read_the_file(char *filename, stack_t **stack);
char *parse_line(int linenum, char *line);
int is_numeric(char *str);
int is_empty(stack_t *stack);
void push_elem(stack_t **stack, unsigned int line_number);
void pall_elem(stack_t **stack, unsigned int line_number);
void prnt_node(stack_t **stack, unsigned int line_number);
void pop_layer(stack_t **stack, unsigned int line_number);
void swap_elem(stack_t **stack, unsigned int line_number);
void add_layer(stack_t **stack, unsigned int line_number);
void nop_elem(stack_t **stack, unsigned int line_number);
void free_the_stack(stack_t **stack);
void sub_layer(stack_t **stack, unsigned int line_number);
void divide_elem(stack_t **stack, unsigned int line_number);
void mul_elem(stack_t **stack, unsigned int line_number);
void mod_elem(stack_t **stack, unsigned int line_number);
int get_arg(void);
void print_char(stack_t **stack, unsigned int line_number);
void print_str(stack_t **stack, unsigned int line_number);
void rotl_str(stack_t **stack, unsigned int line_number);
void rotr_str(stack_t **stack, unsigned int line_number);


#endif
