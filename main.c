#include "monty.h"
char *value;
int EXIT_STATUS;
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of pointers to the arguments
 * Return: 0 on success, exit 1 on failure
 */
int main(int argc, char **argv)
{
	FILE *file;
	ssize_t nread;
	char *line = NULL;
	size_t len = 0;
	char *op;
	unsigned int line_count = 0;
	stack_t *stack = NULL;
	void (*do_operation)(stack_t **, unsigned int);
	(void)argc;

	file = read_file(argc, argv);

	while ((nread = getline(&line, &len, file)) != -1)
	{
		EXIT_STATUS = 0;
		line_count++;
		tokenize_line(line, &op, &value);
		if (!op && !value)
			continue;

		if (op)
		{
			do_operation = get_op_func(op, line_count);
			if (do_operation == NULL)
				break;
		}
		if (do_operation)
			do_operation(&stack, line_count);
		if (EXIT_STATUS != 0)
			break;
	}

	fclose(file);
	_free_list(&stack);
	free(line);

	exit(EXIT_STATUS);
}
