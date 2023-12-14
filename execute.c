#include "monty.h"
/**
* execute - executes the opcode
* @head: head stack
* @line_count: line count
* @file: monty file
* @content: line content
* Return: nothing
*/
int fun_execute(char *content, stack_t **head, unsigned int line_count,
		FILE *file)
{
	instruction_t options[] = {
				{"push", push}, {"pall", print_stack}, {"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", div_s},
				{"mul", mul},
				{"mod", mod},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return;
	bus.arg = strtok(NULL, " \n\t");
	while (options[i].opcode && op)
	{
		if (strcmp(op, options[i].opcode) == 0)
		{	options[i].f(head, line_count);
			return (0);
		}
		i++;
	}
	if (op && options[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line_count, op);
		fclose(file);
		free(content);
		free_node(*head);
		exit(EXIT_FAILURE); }
	return (1);
}
