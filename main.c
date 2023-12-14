#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	char *file_name;
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/* open file*/
	file_name = argv[1];
	fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		free_stack();
		exit(EXIT_FAILURE);
	}

	read_file(fd);
	fclose(fd);

	free_stack();
	return (0);
}

/**
 * free_stack - Frees nodes in the stack.
 */
void free_stack(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_num;
	char *opcode, *value, *buffer = NULL;
	size_t len = 0;

	for (line_num = 1; getline(&buffer, &len, fd) != -1; line_num++)
	{
		if (buffer == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_stack();
			exit(EXIT_FAILURE);
		}

		opcode = strtok(buffer, "\n ");
		value = strtok(NULL, "\n ");

		find_func(opcode, value, line_num);
	}
	free(buffer);
}
