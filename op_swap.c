#include "monty.h"

/**
  *swap - implements the swap opcode
  *@stack: pointer to the stack
  *@line_number: line number in the file
  */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int temp_value;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	temp_value = (*stack)->n;
	(*stack)->n = temp->n;
	temp->n = temp_value;
}
