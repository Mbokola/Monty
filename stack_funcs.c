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
	if(!*stack)
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", linum);
	else
		printf("%d\n", (*stack)->n);
}
