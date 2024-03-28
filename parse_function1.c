#include "monty.h"

/**
 * add_layer - Add first layer data to the sencond top one, and
 * remove the top
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void add_layer(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n + (*stack)->prev->n;
	(*stack)->prev->n = temp;
	pop_layer(stack, line_number);
}

/**
 * nop_elem - print the elements of the stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void nop_elem(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * sub_layer - subtract the top from the second to layer
 * and operate pop
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void sub_layer(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->prev->n = (*stack)->prev->n - (*stack)->n;
	pop_layer(stack, line_number);
}

/**
 * divide_elem - div divides the second top element of the stack by the top
 * element of the stack.
 * and operate pop, unless top == zero
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void divide_elem(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*stack)->prev->n / (*stack)->n;
	(*stack)->prev->n = result;
	pop_layer(stack, line_number);
}

/**
 * mul_elem - multiplies the second top element of the stack with the
 * top element of the stack.
 * and operate pop.
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void mul_elem(stack_t **stack, unsigned int line_number)
{
	int result = 0;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	result = (*stack)->prev->n * (*stack)->n;
	(*stack)->prev->n = result;
	pop_layer(stack, line_number);
}
