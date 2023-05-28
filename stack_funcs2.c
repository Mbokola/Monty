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

/**
 *pchar - prints the ascii char of first element
 *
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void pchar(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n", linum);
		num = 0;
	}
	else if (ptr->n >= 0 && ptr->n < 128)
	{
		printf("%c\n", ptr->n);
		num = 1;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n", linum);
		num = 0;
	}
}

/**
 *pstr - prints the ascii char of elements
 *Description - stops printing if element equals 0, value not an ascii, end of
 *stack
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void pstr(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	(void)linum;
	if (!*stack)
		printf("\n");
	else
	{
		while (ptr)
		{
			if (ptr->n > 0 && ptr->n < 128)
				putchar(ptr->n);
			else
				break;
			ptr = ptr->next;
		}
		printf("\n");
	}

	num = 1;
}
