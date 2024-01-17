#include "monty.h"


void free_stack(stack_t *stack);
int is_digit(char *str);
char **tokenize(char *line);

FILE *file;
char **args;
stack_t *stack;
int line_number;

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the program command line arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char line[120];
	int i;
	instruction_t inst[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {NULL, NULL}
	};

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);

	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (fgets(line, 120, file))
	{
		line_number++;
		args = tokenize(line);
		if (args == NULL)
			continue;
		for (i = 0; inst[i].opcode != NULL; i++)
		{
			if (strcmp(args[0], inst[i].opcode) == 0)
			{
				inst[i].f(&stack, line_number);
				break;
			}
			if (inst[i + 1].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
				free(args), fclose(file), free_stack(stack), exit(EXIT_FAILURE);
			}
		}
		free(args);
	}
	fclose(file), free_stack(stack);
	return (0);
}

/**
 * tokenize - Splits a line into an array of strings
 * @line: Is the line to spilt
 * Return: An array of strings
*/
char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * 3);

	if (tokens == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file), exit(EXIT_FAILURE);
	}
	tokens[0] = strtok(line, " \t\n");
	if (tokens[0] == NULL)
	{
		free(tokens);
		return (NULL);
	}
	tokens[1] = strtok(NULL, " \t\n");
	tokens[2] = NULL;
	return (tokens);
}


/**
 * is_digit - Checks if a string consists of digits only
 * @str: Is the string to check
 * Return: 1 if true or 0 if false
*/
int is_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			continue;
		if (str[i] >= '0' && str[i] <= '9')
			continue;
		return (0);
	}
	return (1);
}
