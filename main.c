#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	char *file_cont;
	size_t n = 0;
	ssize_t line = 1;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	/*If the user does not give any file or more than one argument */
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");/* open file on read*/
	bus.file = file;
	if (!file)/*if not possible to open the file*/
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line > 0)/*get the file contener*/
	{
		file_cont = NULL;
		line = getline(&file_cont, &n, file);
		bus.content = file_cont;
		count++;
		if (line > 0)
		{
			fun_execute(file_cont, &stack, count, file);
			/*printf("%s\n%d", file_cont, count); this line will rmove it*/
		/* we call the execute function*/
		}
		free(file_cont);
	}
	free_node(stack);
	fclose(file);
	return (0);
}
