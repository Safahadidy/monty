#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#define UNUSED(x) (void)(x)
#define INSTRUCTIONS_COUNT 17
#define STACK 1
#define QUEUE 0
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
 * struct my_data_s - Struct to hold data for the Monty interpreter
 *
 * @line_number: The current line number being executed
 * @arg1: The first argument of the current line being executed (if any)
 * @arg2: The second argument of the current line being executed (if any)
 * @stack: Pointer to the top of the stack
 * @file: Pointer to the file being executed
 * @line: Pointer to the current line being executed
 * @mode: The mode of the Monty interpreter (STACK or QUEUE)
 */
typedef struct my_data_s
{
	int line_number;
	char *arg1;
	char *arg2;
	stack_t *stack;
	FILE *file;
	char *line;
	int mode;
} my_data_t;

extern my_data_t my_data;
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
