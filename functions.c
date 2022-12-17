#include "monty.h"

/*
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

/*
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


/*
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


/*
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


/*
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
		printf("error");
		exit(EXIT_FAILURE);
	}

	aux = ptr->n;
	ptr->n = (ptr->prev)->n;
	(ptr->prev)->n = aux;

}
