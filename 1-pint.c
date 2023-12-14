#include "monty.h"

/**
 * pint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top of the stack.
 * @line_number: line number of the opcode.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
