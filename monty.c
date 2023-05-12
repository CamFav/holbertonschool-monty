#include "monty.h"
/**
 * read_file - open a file
 * @argc: number of program args
 * @argv: program args
 * Return: the file on succes, exit 1 else
 */
FILE *read_file(int argc, char **argv)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}

/**
 * tokenize_line - tokenize a string using strtok
 * @line:the string to tokenize
 * @op: the first token
 * @value: the second token
 */
void tokenize_line(char *line, char **op, char **value)
{
	*op = strtok(line, " $\n\t");
	*value = strtok(NULL, " $\n\t");
}

/**
 * isnumber - check if a string contains only digits and signs
 * @data: the number to check
 * Return: 1 if data contains only number, 0 else
 */
int isnumber(char *data)
{
	int i = 0;

	if (data == NULL)
		return (0);

	if (data[0] == '-')
		i++;

	while (data[i])
	{
		if (!isdigit(data[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * _free_list - free a doubly linked list of stack_t type
 * @head: the head of the stack to free
 */
void _free_list(stack_t **head)
{
	stack_t *tmp;

	while (*head)
	{
		tmp = *head;
		(*head) = (*head)->next;
		free(tmp);
		tmp = NULL;
	}
	head = NULL;
}
