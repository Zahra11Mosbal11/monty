#include "monty.h"
/**
 * add_stack - adds a new node at the beginning.
 * @head: the node
 * @n: the data
 * Return: void
 */
void add_stack(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*head)
		(*head)->prev = new;
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
/**
 * add_queue - new node at the end
 * @head: the node
 * @n: the data
 * Return: void
 */
void add_queue(stack_t **head, int n)
{
	stack_t *last, *curnt = *head;

	last = malloc(sizeof(stack_t));
	if (last == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		/*exit(EXIT_FAILURE);*/
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
		curnt->next = last;
		last->prev = curnt;
	}
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
