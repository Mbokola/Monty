#include "monty.h"
int num = 0;

/**
 *line_proc - Process input line by removing spaces if any
 *@file: Opened file
 *
 *Return: Nothing
 */
void line_proc(FILE *file)
{
	char *buffer = NULL;
	size_t n = 0;
	ssize_t i = 0, length = 0, len = 0, end = 0;
	stack_t *head = NULL;
	int line = 1;

	while ((length = getline(&buffer, &n, file)) != -1)
	{
		if (strspn(buffer, " \t\n") == strlen(buffer))
			continue;
		length -= 1;
		len = 0;
		end = 0;
		for (i = 0; i < length && buffer[len]; i++)
		{
			if (!isspace(buffer[i]))
			{
				buffer[len] = buffer[i];
				len++;
				continue;
			}
			if (i && end && isspace(buffer[i]) && !isspace(buffer[i - 1]))
			{
				buffer[len] = '\0';
				continue;
			}
			if (isspace(buffer[i]) && end)
				continue;
			if (i && isspace(buffer[i]) && !isspace(buffer[i - 1]))
			{
				buffer[len] = buffer[i];
				len++;
				end++;
				continue;
			}
		}
		if (buffer[len])
			buffer[len] = '\0';
		extract(buffer, &head, line, file);
		line++;
	}
	free(buffer);
	fclose(file);
	set_free(&head);
}

/**
 *extract - extracts the opcode, and argument
 *@buffer: processed input line
 *@head: The stack
 *@linum: Line being processed
 *@file: open file
 *
 *Return: Nothing
 */
void extract(char *buffer, stack_t **head, int linum, FILE *file)
{
	char *ptr = NULL;
	int i = 0, c;

	for (i = 0; buffer[i]; i++)
	{
		if (buffer[i] == ' ')
		{
			buffer[i] = '\0';
			ptr = &buffer[i + 1];
		}
	}
	if (ptr && strspn(ptr, " \t\n") == strlen(ptr))
		ptr = NULL;
	if (ptr)
	{
		for (i = 0; ptr[i]; i++)
		{
			c = ptr[i];
			if (c > 47 && c < 58)
				continue;
			ptr = NULL;
			break;
		}
		if(ptr && !ptr[i])
			num = atoi(ptr);
	}
	if (!ptr && strcmp(buffer, "pall"))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", linum);
		free(buffer);
		set_free(head);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	opcode_exe(head, buffer, linum, file);
}

/**
 *opcode_exe - executes the opcode
 *@stack: The stack
 *@str: opcode for matching
 *@linum: Line number
 *@file: open file
 *
 *Return: Nothing
 */
void opcode_exe(stack_t **stack, char *str, int linum, FILE *file)
{
	int i, track = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(str, op[i].opcode) == 0)
		{
			op[i].f(&*stack, linum);
			if (i != 1)
				track = 1;
			break;
		}
	}
	if (op[i].opcode == NULL || (track && !*stack))
	{
		if (!track)
			dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n", linum, str);
		free(str);
		if (*stack)
			set_free(stack);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}

/**
 *set_free - free's the stack
 *@stack: The stack
 *
 *Return: Nothing
 */
void set_free(stack_t **stack)
{
	stack_t *ptr = NULL;

	while (*stack)
	{
		ptr = (*stack)->next;
		free(*stack);
		*stack = ptr;
	}
}
