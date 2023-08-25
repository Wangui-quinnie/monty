#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @argument: The argument for the push opcode.
 * @line_number: The line number of the current opcode.
 */
void push(stack_t **stack, char *argument, unsigned int line_number)
{
	int value;

	if (argument == NULL || !is_valid_integer(argument))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(argument);
	push_stack(stack, value);
}
