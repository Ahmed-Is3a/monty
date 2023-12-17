#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

void open_file(char *file_name);
int parse_line(char *buffer, int line_number, int format);
void read_file(FILE *);
void find_func(char *, char *, int);

stack_t *add_to_stack(int n);
void free_stack(void);
void push(stack_t **stack, unsigned int);
void pall(stack_t **stack, unsigned int);
void pint(stack_t **stack, unsigned int);
void add(stack_t **stack, unsigned int);
void nop(stack_t **stack, unsigned int);
void pop(stack_t **stack, unsigned int);
void swap(stack_t **stack, unsigned int);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_num);
void multiply(stack_t **stack, unsigned int line_num);
void mod(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotr(stack_t **stack, unsigned int line_num);

void call_func(op_func, char *, char *, int);

/*Error hanlding*/
void handle_errors(int error_code, ...);

#endif
