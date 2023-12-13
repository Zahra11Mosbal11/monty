#include "monty.h"
/**
 * print_stack - Adds a node to the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void print_stack(stack_t **head, unsigned int line_cont)
{
	stack_t *node;

	(void) line_cont;
	if (head == NULL)
		exit(EXIT_FAILURE);
	node = *head;
	while (node != NULL)
	{
		printf("%d\n", node->n);
		node = node->next;
	}
}
/**
 * pint - Prints the top node of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void pint(stack_t **head, unsigned int line_cont)
{
	if (head == NULL || *head == NULL)
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_cont);
	printf("%d\n", (*head)->n);
}
/**
 * pop - Adds a node to the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void pop(stack_t **head, unsigned int line_cont)
{
	stack_t *node;

	if (head == NULL || *head == NULL)
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_cont);

	node = *head;
	*head = node->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(node);
}
/**
 * add - Adds the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void add(stack_t **head, unsigned int line_cont)
{
	int sum;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "add");
	(*head) = (*head)->next;
	sum = (*head)->n + (*head)->prev->n;
	(*head)->n = sum;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * swap - Swaps the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void swap(stack_t **head, unsigned int line_cont)
{
	stack_t *node;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "swap");
	node = (*head)->next;
	(*head)->next = node->next;
	if (node->next != NULL)
		node->next->prev = *head;
	node->next = *head;
	(*head)->prev = node;
	node->prev = NULL;
	*head = node;
}
