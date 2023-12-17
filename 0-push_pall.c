#include "monty.h"

/**
 * push - pushes an element to the stack.
 * @new_node: Pointer to the new node.
 * @line_num: Interger representing the line number of of the opcode.
 */
void push(stack_t **new_node, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * pall -  prints all the values on the stack, starting from the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: line number.
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void)line_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
