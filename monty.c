#include "monty.h"

/**
 *main - Program entry
 *@ac: Number of arguments
 *@av: The arguments
 *
 *Return: if succesful
 */
int main(int ac, char **av)
{
	FILE *fd = NULL;

	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_proc(fd);
	return (0);
}
