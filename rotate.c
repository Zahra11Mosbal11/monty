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
	stack_t *tmp = *head, *tmp1;

	(void)count;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp1 = (*head)->next;
	tmp1->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = tmp1;
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

	tmp = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
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
