#include "monty.h"

/**
 * mod - Computes the rest of the division of the second top element by
 * the top element
 *
 * @stack: Is a pointer to the pointer to the stack
 * @line_number: Is the current line number of the opcode
 * Return: void
*/

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	int size = 0;

	(void) (line_number);

	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	if (size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free(args), fclose(file), free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free(args), fclose(file), free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n %= temp->n;
	free(temp);
	if (*stack)
		(*stack)->prev = NULL;
}
