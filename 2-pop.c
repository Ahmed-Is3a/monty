#include "main.h"

/**
 * pop -  removes the top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of the opcode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL) /* if empty*/
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
