#include "monty.h"


/**
 * rotl - rotates the stack to the top.
 * The top element of the stack becomes the last one,
 *  and the second top element of the stack becomes the first one
 * rotl never fails
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
