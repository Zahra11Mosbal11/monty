#include "monty.h"
/**
 * add_stack - adds a new node at the beginning.
 * @head: the node
 * @n: the data
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	new->prev = NULL;
	new->next = *head;
	if (*head != NULL)
		(*head)->prev = new;
	*head = new;
	return (new);
}
/**
 * add_queue - new node at the end
 * @head: the node
 * @n: the data
 * Return: the address of the new element, or NULL if it failed
 */
stack_t *add_queue(stack_t **head, const int n)
{
	stack_t *last, *curnt = *head;

	last = malloc(sizeof(stack_t));
	if (last == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	last->n = n;
	last->prev = NULL;
	last->next = NULL;

	if (*head == NULL)
		*head = last;
	else
	{
		while (curnt->next != NULL)
			curnt = curnt->next;
		last->prev = curnt;
		curnt->next = last;
	}
	return (last);
}
/**
 * free_node - Frees nodes in the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 */
void free_node(stack_t *head)
{
	stack_t *node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head->next;
		free(head);
		head = node;
	}
}
/**
 * nop - Does nothing.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void nop(stack_t **head, unsigned int line_cont)
{
	(void)head;
	(void)line_cont;
}