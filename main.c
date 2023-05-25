#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
 * main - Monty code interpreter
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
return (EXIT_FAILURE);
}

FILE *file = fopen(argv[1], "r");
if (!file)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
return (EXIT_FAILURE);
}

char *line = NULL;
size_t size = 0;
ssize_t read_line;
stack_t *stack = NULL;
unsigned int counter = 0;

while ((read_line = getline(&line, &size, file)) != -1)
{
counter++;

if (line[read_line - 1] == '\n')
line[read_line - 1] = '\0';

execute(line, &stack, counter, file);
}

free(line);
free_stack(stack);
fclose(file);

return (0);
}
