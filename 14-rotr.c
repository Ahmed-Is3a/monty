#include "monty.h"


/**
 * rotr - rotates the stack to the bottom.
 * The last element of the stack becomes the top element of the stack
 * rotr never fails
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, unsigned int line_num)
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
	(*stack) = (*stack)->prev;

	tmp->prev->next = NULL;
	tmp->prev = NULL;
}
