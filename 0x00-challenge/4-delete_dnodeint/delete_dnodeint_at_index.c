#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	/*dlistint_t *saved_head;*/
       	dlistint_t *current = (*head);
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	/*saved_head = *head;*/
	p = 0;
	if (index == 0)
	{
		tmp = current->next;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
		free(current);
		*head = tmp;
		return (1);
	}
	while (p < index && current != NULL)
	{
		current = current->next;
		p++;
	}
	if (current == NULL)
	{
		return (-1);
	}
	tmp = current->next;
	tmp->prev = current->prev;
	current->prev->next = tmp;

	free(current);
	/*
	else
	{
		(*current->prev->prev = (*head)->prev;
		free(*current;
		if ((*current->next)
			(*current->next->prev = (*head)->prev;
		*head = saved_head;
	}*/
	return (1);
}
