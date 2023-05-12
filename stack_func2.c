#include "monty.h"
/**
 * pop - removes first element of stack
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 *
 * Return: Nothing.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *topNode = NULL;

	if (!*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}
	topNode = (*stack);

	if (*stack)
		(*stack)->prev = NULL;

	*stack = (*stack)->next;
	free(topNode);
	/* Add logic to remove the top element from the stack */
}

/**
 * nop - do nothing...
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swap the two first elements of the stack
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * _add - add the data of the 2 first node of the stack, delete one
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
