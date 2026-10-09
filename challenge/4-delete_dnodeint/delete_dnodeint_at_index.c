#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: pointer to head pointer
 * @index: index of node to delete
 *
 * Return: 1 if success, -1 if fail
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    unsigned int i;

    if (head == NULL || *head == NULL)
        return (-1);

    tmp = *head;

    if (index == 0)
    {
        *head = tmp->next;
        if (*head)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    for (i = 0; tmp && i < index; i++)
        tmp = tmp->next;

    if (!tmp)
        return (-1);

    if (tmp->next)
        tmp->next->prev = tmp->prev;

    if (tmp->prev)
        tmp->prev->next = tmp->next;

    free(tmp);
    return (1);
}
