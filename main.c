#include "monty.h"

/**
 * main - main
 * @argc: argc
 * @argv: argv
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	char *line = NULL;
	FILE *fp;
	size_t len = 0;
	ssize_t read;
	int line_number = 1;
	char *token;
	stack_t *stack = NULL;/*Malloc(sizeof(stack_t))??*/
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		token = strtok(line, " \n");
		if (!token)
			continue;
		f = get_op_func(token);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			return (EXIT_FAILURE);
		}
		f(&stack, line_number);
		line_number++;
	}
	fclose(fp);
	free(line);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
