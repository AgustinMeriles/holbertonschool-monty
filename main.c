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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	/*fd = open(argv[1], O_WRONLY);*/
	fp = fopen(argv[1], "r");

	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		printf("Retrieved line of length %ld:\n", read);
		printf("%s", line);
		line_number++;
	}

	return (EXIT_SUCCESS);

}
