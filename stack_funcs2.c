#include "monty.h"

/**
 *mod - modulo second element by first element
 *Description: Result is stored in second node and first node is removed
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void mod(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n", linum);
		num = 0;
	}
	else if (!ptr->n)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", linum);
		num = 0;
	}
	else
	{
		ptr->next->n %= ptr->n;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		num = 1;

	}
}
