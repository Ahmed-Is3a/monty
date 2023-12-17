#include "monty.h"


/**
 * pstr - prints the string starting at the top of the stack, followed by a new line.
 *
 * The integer stored in each element of the stack is treated
 * as the ascii value of the character to be printed
 * The string stops when either:
 *		the stack is over
 *		the value of the element is 0
 *		the value of the element is not in the ascii table
 * If the stack is empty, print only a new line
 *
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_num: Interger representing the line number of of the opcode.
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	int ascii;
	stack_t *tmp;

	(void)line_num;
	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
