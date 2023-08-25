#include "monty.h"

/**
 * main - Entry point of the Monty interpreter.
 * @argc: The number of command-line arguments.
 * @argv: An array containing the command-line arguments.
 * Return: 0 on success, on failure a number
 */
int main(int argc, char *argv[])
{
	FILE *bytecode_file;
	char *line = NULL;
	size_t line_len = 0;
	unsigned int line_number = 0;
	ssize_t read = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	bytecode_file = fopen(argv[1], "r");
	if (!bytecode_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((read = getline(&line, &line_len, bytecode_file) != -1))
	{
		line_number++;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';
		if (read == 0 || line[0] == '#')
			continue;
		execute_opcode(line, line_number, &stack);
	}
	free(line);
	fclose(bytecode_file);
	return (EXIT_FAILURE);
}
/**
  *execute_opcode - extracts the opcode from each line
  *@stack: double pointer to the head of the stack
  *@line: is the line
  *@line_number: line number of the opcode
  */
void execute_opcode(char *line, unsigned int line_number, stack_t **stack)
{
	char *opcode, *argument;

	opcode = strtok(line, " \t\n");
	if (opcode != NULL && strcmp(opcode, "push") == 0)
	{
		argument = strtok(NULL, " \t\n");
		push(stack, argument, line_number);
	} else if (opcode != NULL && strcmp(opcode, "pall") == 0)
	{
		pall(stack, line_number);
	}
	else
	{
		handle_unknown_opcode(opcode, line_number);
	}
}

/**
  *handle_unknown_opcode - handles cases where an unknown opcode
  *is encountered
  *@line_number: line number of the opcode
  *@opcode: opcode
  */
void handle_unknown_opcode(char *opcode, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
/**
 * is_valid_integer - Checks if a given string is a valid integer.
 * @str: The string to check.
 *
 * Return: 1 if the string is a valid integer, otherwise 0.
 */
int is_valid_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * push_stack - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: The value to push onto the stack.
 */
void push_stack(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new_node;
	*stack = new_node;
}
