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

    /* delete head */
    if (index == 0)
    {
        *head = tmp->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(tmp);
        return (1);
    }

    /* traverse to node */
    for (i = 0; tmp != NULL && i < index; i++)
        tmp = tmp->next;

    if (tmp == NULL)
        return (-1);

    /* unlink */
    if (tmp->next != NULL)
        tmp->next->prev = tmp->prev;

    if (tmp->prev != NULL)
        tmp->prev->next = tmp->next;

    free(tmp);
    return (1);
}


