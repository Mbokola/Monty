#ifndef monty
#define monty
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern int num;
void line_proc(FILE *file);
void extract(char *buffer, stack_t **head, int linum, FILE *file);
void opcode_exe(stack_t **stack, char *str, int linum, FILE *file);
void push(stack_t **stack, unsigned int linum);
void pall(stack_t **stack, unsigned int linum);
void set_free(stack_t **stack);
void pint(stack_t **stack, unsigned int linum);
void line_proc1(char **buffer, ssize_t length);
void pop(stack_t **stack, unsigned int linum);
void swap(stack_t **stack, unsigned int linum);
void add(stack_t **stack, unsigned int linum);
void nop(stack_t **stack, unsigned int linum);
void sub(stack_t **stack, unsigned int linum);
void divi(stack_t **stack, unsigned int linum);
void mul(stack_t **stack, unsigned int linum);
void mod(stack_t **stack, unsigned int linum);
void pchar(stack_t **stack, unsigned int linum);
#endif
