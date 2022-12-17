#include "monty.h"

/**
 * free_stack - Free list
 *
 * @stack: stack
 */

void free_stack(stack_t *stack)
{
	stack_t *ptr;

	while (stack)
	{
		ptr = stack;
		stack = stack->next;
		free(ptr);
	}
}
