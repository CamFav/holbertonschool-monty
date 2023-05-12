#include "monty.h"

/**
 * _sub - sub the data of the 2 first node of the stack, delete one
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _div - div the data of the 2 first node of the stack, delete one
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mul - multiplies the data of the 2 first node of the stack, delete one
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * _mod - mod the data of the 2 first node of the stack, delete one
 * @stack: point the head of the stack
 * @line_number: the number of the line of the file we read
 */
void _mod(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		EXIT_STATUS = EXIT_FAILURE;
		return;
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
