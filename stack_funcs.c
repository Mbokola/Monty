#include "monty.h"
/**
 *push - Adds new element to the top
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Notthing
 */
void push(stack_t **stack, unsigned int linum)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)linum;
	if (!new_node)
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		(*stack)->prev = new_node;
		new_node->next = *stack;
		*stack = new_node;
	}
	if (!num)
		num = 1;

}

/**
 *pall - prints eleents on the stack
 *@stack: The stack
 *@linum: Line number
 *
 *Retutn: Nothing
 */
void pall(stack_t **stack, unsigned int linum)
{
	stack_t *ptr = *stack;

	(void)linum;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}

}

/**
 *pint - prints element at top of stack
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void pint(stack_t **stack, unsigned int linum)
{
	if (!*stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", linum);
		num = 0;
	}
	else
	{
		printf("%d\n", (*stack)->n);
		num = 1;
	}
}
/**
 *pop - deletes element at top of stack
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void pop(stack_t **stack, unsigned int linum)
{
	stack_t *popper = *stack;

	(void)linum;
	if (*stack)
	{
		*stack = popper->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(popper);
		popper = NULL;
		num = 1;
	}
	else
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", linum);
		num = 0;
	}

}

/**
 *swap - swaps firt 2 elements of stack
 *@stack: The stack
 *@linum: Line number
 *
 *Return: Nothing
 */
void swap(stack_t **stack, unsigned int linum)
{
	stack_t *swap = *stack;

	if (!*stack || !(*stack)->next)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n", linum);
		num = 0;
	}
	else
	{
		*stack = (*stack)->next;
		swap->prev = *stack;
		swap->next = (*stack)->next;
		(*stack)->next = swap;
		(*stack)->prev = NULL;
		num = 1;
	}
}
