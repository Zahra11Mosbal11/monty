#include "monty.h"
/**
 * sub - Adds the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void sub(stack_t **head, unsigned int line_cont)
{
	int sub;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "sub");
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	sub = (*head)->n - (*head)->prev->n;
	(*head)->n = sub;
	free((*head)->prev);
	(*head)->prev = NULL;
}
