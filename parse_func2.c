#include "monty.h"

/**
 * mod_elem - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * and operate pop, unless top equal zero
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void mod_elem(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->prev->n % (*stack)->n;
	(*stack)->prev->n = result;
	pop(stack, line_number);
}

/**
 * print_char - print the top most value as a char if not out of range
 * @stack: stack
 * @line_number: line_number
 * Return: nothing
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);
}

/**
 * print_str - print the string starting at the top of the stack followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	if (tmp == NULL)
	{
		putchar('\n');
		return;
	}

	while (tmp && (tmp->n < 128 && tmp->n > 0))
	{
		fprintf(stdout, "%c", tmp->n);
		tmp = tmp->prev;
	}
	putchar('\n');
}

/**
 * print_str_ln - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void print_str_ln(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL, *first = NULL;

	(void)line_number;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	first = *stack;
	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	first->prev = NULL;
	first->next = NULL;
	temp = *stack;
	while (tmp->prev != NULL)
		tmp = tmp->prev;
	tmp->prev = first;
	first->next = tmp;
}

/**
 * print_str_line - prints the string starting at the top of the stack, followed
 * by a new line, while the interger being treated as an ascii value
 * @stack: stack
 * @line_number: line number
 * Return: nothing
 */
void print_str_line(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *first = *stack, *last = NULL;
	(void)line_number;
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		return;
	}
	tmp = *stack;
	while (tmp->prev->prev != NULL)
		tmp = tmp->prev;
	last = tmp->prev;
	last->next = NULL;
	tmp->prev = NULL;
	last->prev = first;
	first->next = last;
	*stack = last;
}
