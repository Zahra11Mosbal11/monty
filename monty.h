#ifndef MONTY_H
#define MONTY_H

#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

/* the main function for stack & queue */
void add_stack(stack_t **head, int n);
void add_queue(stack_t **head, int n);
void free_node(stack_t *head);
int fun_execute(char *content, stack_t **head, unsigned int line_count,
		FILE *file);

/* mandatory functions */
void push(stack_t **head, unsigned int counter);
void print_stack(stack_t **head, unsigned int line_cont);
void pint(stack_t **head, unsigned int line_cont);
void pop(stack_t **head, unsigned int line_cont);
void nop(stack_t **head, unsigned int line_cont);
void add(stack_t **head, unsigned int line_cont);
void swap(stack_t **head, unsigned int line_cont);

/*advanced function */
void sub(stack_t **head, unsigned int line_cont);
void div_s(stack_t **head, unsigned int line_cont);
void mul(stack_t **head, unsigned int line_cont);
void mod(stack_t **head, unsigned int line_cont);
void pchar(stack_t **head, unsigned int count);
void pstr(stack_t **head, unsigned int count);
void rot1(stack_t **head, unsigned int count);
void rot(stack_t **head, unsigned int count);
void is_stack(stack_t **head, unsigned int line_cont);
void is_queue(stack_t **head, unsigned int line_cont);

#endif /* MONTY_H */
