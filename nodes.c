#include "monty.h"
/**
 * create_node - create a new node stack_t type
 * Return: a pointer to the created node
 */
stack_t *create_node()
{
	stack_t *new;

	if (!isnumber(value))
	{
		return (NULL);
	}

	new = malloc(sizeof(stack_t) * 1);

	if (new == NULL)
		return (NULL);

	new->n = atoi(value);
	new->next = NULL;
	new->prev = NULL;

	return (new);
}

/**
 * get_op_func - search for the op function in the struct
 * @op: the string to compare
 * @line_count: the number of the line of the file we read
 * Return: a pointer to the opfunction
 */
void (*get_op_func(char *op, int line_count))(stack_t **, unsigned int)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"mul", _mul},
		{"sub", _sub},
		{"div", _div},
		{"mod", _mod},
		{"nop", nop},
		{0, NULL},
	};

	int i = 0;

	while (op && ops[i].opcode != NULL)
	{
		if (strcmp(op, ops[i].opcode) == 0)
			return (ops[i].f);
		i++;
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
	EXIT_STATUS = EXIT_FAILURE;

	return (NULL);
}
