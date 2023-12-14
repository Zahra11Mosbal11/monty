#include "monty.h"

/**
 * pchar - print char at top of stack
 * @head: head
 * @count: line
 *
 * Return: none
 */

void f_pchar(stack_t **head, unsigned int count)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}


/**
 * pstr - print string
 * @head: head
 * @count: line
 *
 * Return: none
 */

void pstr(stack_t **head, unsigned int count)
{
	stack_t *h;
	(void)count;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
