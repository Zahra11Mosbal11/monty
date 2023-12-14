#include "monty.h"
/**
 * sub - Subs the top two elements of the stack.
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
/**
 * div_s - divs the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void div_s(stack_t **head, unsigned int line_cont)
{
	int div;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "div");
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cont);
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	div = (*head)->n / (*head)->prev->n;
	(*head)->n = div;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * mul - muls the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void mul(stack_t **head, unsigned int line_cont)
{
	int mul;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "mul");
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	mul = (*head)->n * (*head)->prev->n;
	(*head)->n = mul;
	free((*head)->prev);
	(*head)->prev = NULL;
}
/**
 * mod - mods the top two elements of the stack.
 * @head: Pointer to a pointer pointing to top node of the stack.
 * @line_cont: Interger representing the line number of of the opcode.
 */
void mod(stack_t **head, unsigned int line_cont)
{
	int mod;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't %s, stack too short\n", line_cont, "mod");
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_cont);
		fclose(bus.file);
		free(bus.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	(*head) = (*head)->next;
	mod = (*head)->n % (*head)->prev->n;
	(*head)->n = mod;
	free((*head)->prev);
	(*head)->prev = NULL;
}
