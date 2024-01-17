#include "monty.h"
/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Is a pointer to the pointer to the stack
 * @line_number: Is the current line number of the opcode
 * Return: void
*/

void swap(stack_t **stack, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free(args), fclose(file);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
}
