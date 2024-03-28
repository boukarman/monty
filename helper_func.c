#include "monty.h"

/**
 * free_stack - free stack
 * @stack: stack
 *
 * Return: nothing
 */

void free_stack(stack_t **stack)
{
	stack_t *tmp = NULL;

	if (*stack == NULL)
		return;
	while (*stack != NULL)
	{
		tmp = *stack;
		*stack = (*stack)->prev;
		free(tmp), tmp = NULL;
	}
}

/**
 * is_stack_empty - check if stack empty
 * @stack: stack
 *
 * Return: 1 if empty and 0 if not
 **/

int is_stack_empty(stack_t *stack)
{
	return (stack == NULL);
}
