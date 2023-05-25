#include "monty.h"

struct global_data_t global_data;

/**
 * op_push - Pushes an element to the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_push(stack_t **stack, unsigned int line_number)
{
int value;
stack_t *new_node;

if (global_data.arg == NULL)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

value = atoi(global_data.arg);
if (value == 0 && strcmp(global_data.arg, "0") != 0)
{
fprintf(stderr, "L%u: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}
new_node->n = value;
new_node->prev = NULL;

if (*stack != NULL)
{
new_node->next = *stack;
(*stack)->prev = new_node;
}
else
{
new_node->next = NULL;
}

*stack = new_node;
}

/**
 * op_pall - Prints all the values on the stack
 * @stack: Double pointer to the head of the stack
 * @line_number: Line number in the Monty byte code file
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
stack_t *temp = *stack;

(void)line_number;

while (temp != NULL)
{
printf("%d\n", temp->n);
temp = temp->next;
}
}
