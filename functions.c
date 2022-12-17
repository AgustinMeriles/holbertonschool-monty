#include "monty.h"

/**
 * push - function that pushes an element to the stack
 * @stack: the stack of values;
 * @line_number: Unused unsigned int;
 */
void push(stack_t **stack, UNUSED unsigned int line_number)
{
	int num = atoi(strtok(NULL, " \n"));

	stack_t *node = NULL;
	stack_t *ptr = *stack;

	node = malloc(sizeof(stack_t));

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node->n = num;

	node->next = NULL;

	node->prev = NULL;

	if (!*stack)
		*stack = node;

	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = node;
		node->prev = ptr;
	}
}

/**
 * pall - function that prints all the values on the stack
 * @stack: the stack of values;
 * @line_number: Unused unsigned int;
 */
void pall(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		if (!(ptr->next))
			break;

		ptr = ptr->next;
	}

	while (ptr)
	{
		if (ptr->n)
			printf("%d\n", ptr->n);
		else
			printf("0\n");

		ptr = ptr->prev;
	}
}


/**
 * pint - prints the value of rhe top of the stack, followed by a new line
 * @stack: the stack;
 * @line_number: Unused unsigned int;
 */
void pint(stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		if (!(ptr->next))
			break;

		ptr = ptr->next;
	}

	if (ptr->n)
		printf("%d\n", ptr->n);
	else
		printf("0\n");
}


/**
 * pop - removes the top element of the stack
 * @stack: the stack
 * @line_number: Unused unsigned int;
 */
void pop(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *ptr = *stack;

	while (ptr)
	{
		if (!(ptr->next))
			break;
		ptr = ptr->next;
	}

	if (!(ptr->prev))
	{
		free(ptr);
		*stack = NULL;
	}
	else
	{
		(ptr->prev)->next = NULL;
		free(ptr);
	}
}


/**
 * swap - swap the top two elements of the stack
 * @stack: the stack
 * @line_number: Unused unsigned int;
 */
void swap(UNUSED stack_t **stack, UNUSED unsigned int line_number)
{
	stack_t *ptr = *stack;
	size_t i;
	int aux = 0;

	for (i = 0; ptr; i++)
	{
		if (!(ptr->next))
			break;
		ptr = ptr->next;
	}

	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = ptr->n;
	ptr->n = (ptr->prev)->n;
	(ptr->prev)->n = aux;

}
