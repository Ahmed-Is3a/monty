#include "monty.h"

/**
 * multiply - multiplies the second top element of the stack with
 * the top element of the stack.
 *
 * If the stack contains less than two elements,
 * print the error message L<line_number>: can't mul, stack too short,
 * followed by a new line, and exit with the status EXIT_FAILURE
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 *		The top element of the stack contains the result
 *		The stack is one element shorter
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void multiply(stack_t **stack, unsigned int line_num)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		free_stack();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	result = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
