#include "monty.h"

/**
 * print_char -  prints the char at the TOS, followed by new line.
 *
 * The integer stored at the top of the stack is treated as
 * the ascii value of the character to be printed
 * If the value is not in the ascii table (man ascii)
 * print the error message L<line_number>: can't pchar, value out of range,
 * followed by a new line, and exit with the status EXIT_FAILURE
 * If the stack is empty, print the error message
 * L<line_number>: can't pchar, stack empty, followed by a new line,
 * and exit with the status EXIT_FAILURE
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	/* if stack is not initialized or it is empty */
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	ascii = (*stack)->n;
	/* If the value is not in the ascii table */
	if (ascii < 0 || ascii > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii);
}
