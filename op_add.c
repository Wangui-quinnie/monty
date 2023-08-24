#include "monty.h"

/**
  *add - implements the add opcode
  *@stack: pointer to the stack
  *@line_number: line number in the file
  */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
