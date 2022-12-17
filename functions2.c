#include "monty.h"

/**
 * add - function that adds the top two elements of the stack
 * @stack: the stack;
 * @line_number: Unused unsigned int;
 */
void add(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *ptr = *stack;
	size_t i;

	for (i = 0; ptr; i++)
	{
		if (!(ptr->next))
			break;
		ptr = ptr->next;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short" line_number);
		exit(EXIT_FAILURE);
	}

	ptr = ptr->prev;
	ptr->n = (ptr->n) + ((ptr->next)->n);
	pop(stack, line_number);
}


/**
 * nop - function that doesn't do anything
 * @stack: the stack;
 * @line_number: Unused unsigned int;
 */
void nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	;
}

