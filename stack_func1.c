#include "monty.h"

/**
 * push - adding element to stack
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;
	(void)line_number;

	newNode = create_node();

	if (newNode == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	if (stack && *stack)
	{
		(*stack)->prev = newNode;
		newNode->next = *stack;
		*stack = newNode;
		return;
	}
	*stack = newNode;
}

/**
 * pall - print from the start node
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *head = *stack;

	while (stack && *stack)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->next;
	}

	if (stack != NULL)
	{
		*stack = head;
	}
	/* Print all elements of the stack */
}

/**
 * pint - print int in top of stack
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}
	printf("%d\n", (*stack)->n);
	/* Print the value at the top of the stack */
}
