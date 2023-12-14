#include "monty.h"

/**
 * handle_errors - Prints error messages.
 * @error_code: The error codes.
 *
 */
void handle_errors(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		break;
	case 3:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
	}
	free_stack();
	exit(EXIT_FAILURE);
}
