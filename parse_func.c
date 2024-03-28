#include "monty.h"

/**
 * push_elem - push element to stack
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */

void push_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *layer = malloc(sizeof(stack_t));

	(void)line_number;
	if (layer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	layer->n = get_arg();
	layer->next = NULL;
	layer->prev = *stack;
	if (!is_stack_mpty(*stack))
	{
		(*stack)->next = layer;
	}
	*stack = layer;
}

/**
 * pall_elem - print the stack elements
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pall_elem(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void)line_number;
	while (tmp != NULL)
	{
		fprintf(stdout, "%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * pint_node - print the top most stack node
 * @stack: stack
 * @line_number: line number
 *
 * Return: nothing
 */
void pint_node(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop_layer - delete the top most layer of the stack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void pop_layer(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (is_stack_empty(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->prev == NULL)
	{
		(*stack)->next = NULL;
		free(*stack), *stack = NULL;
	}
	else
	{
		temp = *stack;
		/*shouldn't stack -> next == NULL?*/
		*stack = (*stack)->prev;
		temp->prev = NULL;
		temp->next = NULL;
		free(temp), temp = NULL;
	}
}

/**
 * swap_elem - swap the top two elements of the slack
 * @stack: stack
 * @line_number: line_number
 *
 * Return: nothing
 */
void swap_elem(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->prev->n;
	(*stack)->prev->n = tmp;
}
