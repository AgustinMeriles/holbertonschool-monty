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
		/*printf("Line %d:%s", line_number, line);*/
		token = strtok(line, " \n");
		if (!token)
			continue;
		/*printf("token1:%s\n", token);*/
		f = get_op_func(token);
		if (!f)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			return (EXIT_FAILURE);
		}
		f(&stack, line_number);
		/*printf("\n");*/
		line_number++;
	}

	fclose(fp);
	free(line);

	return (EXIT_SUCCESS);

}
