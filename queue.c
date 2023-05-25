#include "monty.h"

/**
 * enqueue - Add an element to the queue
 * @head: Pointer to the head of the queue
 * @n: The value to be added to the queue
 * Return: The newly created node, or NULL on failure
 */
stack_t *enqueue(stack_t **head, int n)
{
stack_t *new_node, *temp;

new_node = malloc(sizeof(stack_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

if (*head == NULL)
{
new_node->prev = NULL;
*head = new_node;
}
else
	{
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = new_node;
new_node->prev = temp;
}

return (new_node);
}

/**
 * dequeue - Remove the element from the front of the queue
 * @head: Pointer to the head of the queue
 * Return: The value of the removed element, or 0 if the queue is empty
 */
int dequeue(stack_t **head)
{
int value;
stack_t *temp;

if (*head == NULL)
return (0);

temp = *head;
value = temp->n;

*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;

free(temp);

return (value);
}

/**
 * print_queue - Print all the elements in the queue
 * @head: Pointer to the head of the queue
 */
void print_queue(stack_t *head)
{
while (head != NULL)
{
printf("%d\n", head->n);
head = head->next;
}
}
