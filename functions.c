#include "monty.h"

/**
 * find_func - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 */
void find_func(char *opcode, char *value, int ln)
{
	int i, flag;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"div", divide},
		{"mul", multiply},
		{"mod", mod},
		{"pchar", print_char},
		{NULL, NULL}};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			call_func(instructions[i].f, opcode, value, ln);
			flag = 0;
		}
	}
	if (flag == 1)
		handle_errors(2, ln, opcode);
}


/**
 * add_to_stack - Creates a node.
 * @n: Number to be added to stack
 * Return: a pointer to the node.
 */
stack_t *add_to_stack(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * call_func - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: the opcode.
 * @value: numeric value.
 * @ln: line numeber for the instruction.
 */
void call_func(op_func func, char *op, char *value, int ln)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			value = value + 1;
			flag = -1;
		}
		if (value == NULL)
			handle_errors(3, ln);
		for (i = 0; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				handle_errors(3, ln);
		}
		node = add_to_stack(atoi(value) * flag);
		func(&node, ln);
	}
	else
		func(&head, ln);
}
