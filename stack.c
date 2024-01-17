#include "monty.h"

/**
 * push - Appends new element at the top of the stack
 * @stack: Is a pointer to the pointer to the stack
 * @line_number: Is the current line number of the opcode
 * Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *temp;

	(void) (line_number);
	if (args[1] == NULL || !is_digit(args[1]))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(args), fclose(file), free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	top = malloc(sizeof(stack_t));
	if (top == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file), free(args), free_stack(*stack), exit(EXIT_FAILURE);
	}
	top->n = atoi(args[1]);
	top->prev = NULL;
	if (*stack == NULL)
	{
		top->next = NULL;
		*stack = top;
		return;
	}
	temp = *stack;
	top->next = *stack;
	*stack = top;
	temp->prev = *stack;
}

/**
 * pall - Prints all the elements of the stack starting from the top
 * @stack: Is a pointer to the pointer to the stack
 * @line_number: Is the current line number of the opcode
 * Return: void
*/

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	(void) (line_number);
	if (*stack == NULL)
		exit(EXIT_FAILURE);
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * free_stack - frees a stack
 * @stack: Is the stack to free
 * Return: void
*/
void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
