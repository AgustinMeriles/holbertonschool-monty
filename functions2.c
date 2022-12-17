#include "monty.h"

/*
 * add - add
 * @stack: stack
 * @line_number: line number
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
		printf("error");
		exit(EXIT_FAILURE);
	}

	ptr = ptr->prev;
	ptr->n = (ptr->n) + ((ptr->next)->n);
	pop(stack, line_number);
}


/*
 * nop - nop
 * @stack: stack
 * @line_number: line number
 */
void nop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	;
}

