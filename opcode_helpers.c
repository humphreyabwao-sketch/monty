#include "monty.h"

/**
 * is_integer - Checks if a string is a valid integer
 * @str: String to check
 * Return: 1 if str is a valid integer, 0 otherwise
 */
int is_integer(char *str)
{
if (str == NULL || *str == '\0')
return (0);

if (*str == '-')
str++;

if (*str == '\0')
return (0);

while (*str != '\0')
{
if (!isdigit(*str))
return (0);
str++;
}

return (1);
}

/**
 * is_stack_empty - Checks if the stack is empty
 * @stack: Pointer to the head of the stack
 * Return: 1 if stack is empty, 0 otherwise
 */
int is_stack_empty(stack_t *stack)
{
return (stack == NULL);
}

/**
 * print_push_error - Prints an error message for push opcode
 * @line_number: Line number in the Monty byte code file
 */
void print_push_error(unsigned int line_number)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

/**
 * print_malloc_error - Prints an error message for malloc failure
 */
void print_malloc_error(void)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

/* Additional helper functions can be defined here */
