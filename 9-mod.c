#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element of
 * the stackby the top element of the stack.
 *
 * If the stack contains less than two elements,
 *   print the error message L<line_number>: can't mod, stack too short,
 *   followed by a new line, and exit with the status EXIT_FAILURE
 * The result is stored in the second top element of the stack,
 *   and the top element is removed, so that at the end:
 *      - The top element of the stack contains the result
 *      - The stack is one element shorter
 * If the top element of the stack is 0, print the error message
 *   "L<line_number>: division by zero",
 *   followed by a new line, and exit with the status EXIT_FAILURE
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	sum = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
