#include "monty.h"

/**
  *pint - implements the pint opcode
  *@stack: pointer to the stack
  *@line_number: line number in the file
  */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
