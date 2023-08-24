#include "monty.h"

/**
 * mul_op - Multiply the second top element of the stack by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number being executed from the Monty file.
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
