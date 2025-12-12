#include "sort.h"

/**
 * swap_nodes - Échange deux nœuds consécutifs dans une liste doublement chaînée
 *
 * @list: Pointeur vers le pointeur de la tête de la liste
 * @node1: Pointeur vers le premier nœud à échanger
 * @node2: Pointeur vers le deuxième nœud à échanger (node1->next)
 *
 * Description: Cette fonction gère la mise à jour des pointeurs prev et next
 * pour effectuer l'échange physique des nœuds.
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    /* Mettre à jour les pointeurs des voisins */
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    /* Échanger node1 et node2 */
    node1->next = node2->next;
    node2->prev = node1->prev;

    node2->next = node1;
    node1->prev = node2;

    /* Si node2 devient la nouvelle tête */
    if (node2->prev == NULL)
        *list = node2;
}

/**
 * insertion_sort_list - Trie une liste doublement chaînée d'entiers
 * en ordre croissant en utilisant le tri par insertion.
 *
 * @list: Pointeur vers le pointeur de la tête de la liste
 *
 * Description: Trie la liste et appelle print_list après chaque échange.
 * La complexité est O(n^2).
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insertion_point, *temp;

    if (!list || !(*list) || !(*list)->next)
        return;

    /* Le tri commence avec le deuxième élément (head->next) */
    current = (*list)->next;

    while (current != NULL)
    {
        /* On prend le nœud actuel et on remonte dans la partie déjà triée */
        insertion_point = current;
        temp = current->next; /* On stocke le nœud suivant pour l'itération */

        while (insertion_point->prev != NULL && 
               insertion_point->n < insertion_point->prev->n)
        {
            /* Le nœud actuel est plus petit que le précédent : on échange */
            swap_nodes(list, insertion_point->prev, insertion_point);
            print_list(*list); /* Afficher la liste après l'échange */
        }
               
        current = temp;
    }
}
