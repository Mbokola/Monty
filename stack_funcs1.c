#include "monty.h"
/**
 *add - adds firt 2 elements of stack
 *Description: Result is stored in second node and first node is removed
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void add(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", linum);
		num = 0;
	}
	else
	{
		ptr->next->n += ptr->n;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		num = 1;

	}
}

/**
 *nop - does nothing
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void nop(stack_t **stack, unsigned int linum)
{
	(void)stack;
	(void)linum;
	num = 1;
}

/**
 *sub - subtracts firt 2 elements of stack
 *Description: Result is stored in second node and first node is removed
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void sub(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n", linum);
		num = 0;
	}
	else
	{
		ptr->next->n -= ptr->n;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		num = 1;

	}
}

/**
 *divi - divides second element by first element
 *Description: Result is stored in second node and first node is removed
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void divi(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n", linum);
		num = 0;
	}
	else if (!ptr->n)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n", linum);
		num = 0;
	}
	else
	{
		ptr->next->n /= ptr->n;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		num = 1;

	}
}

/**
 *mul - multiplies firt 2 elements of stack
 *Description: Result is stored in second node and first node is removed
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void mul(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n", linum);
		num = 0;
	}
	else
	{
		ptr->next->n *= ptr->n;
		*stack = ptr->next;
		free(ptr);
		ptr = NULL;
		num = 1;

	}
}
