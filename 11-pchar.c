#include "main.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		errors_3(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		errors_3(10, line_number);
	printf("%c\n", ascii);
}
