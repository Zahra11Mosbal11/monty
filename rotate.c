#include "monty.h"

/**
 * rotl- rotatefirst item
 * @head: stack head
 * @count: line
 *
 * Return: none
 */

void rotl(stack_t **head, unsigned int count)
{
	stack_t *current_node;
	int top;

	(void)count;

	if (!head || !*head)
		return;

	top = (*head)->n;
	current_node = *head;
	while (current_node->next)
	{
		current_node->n = current_node->next->n;
		current_node = current_node->next;
	}
	current_node->n = top;
}

/**
 * rot - rotate all stack
 * @head: stack head
 * @count: line
 *
 * Return: none
 */

void rot(stack_t **head, unsigned int count)
{
	stack_t *tmp;

	(void)count;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp = *head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*head)->prev = tmp;
	(*head) = tmp;
}
