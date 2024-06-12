/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-dorian.melenotte
** File description:
** my_putlist.c
*/

#include "../my.h"

linked_list_t *my_get_node(linked_list_t *list, int index)
{
    linked_list_t *tmp = list;
    int current = 0;

    while (tmp) {
        if (current == index)
            return tmp;
        current++;
        tmp = tmp->next;
    }
    return NULL;
}
