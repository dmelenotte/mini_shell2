/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-dorian.melenotte
** File description:
** my_putlist.c
*/

#include "../my.h"

linked_list_t *my_delete_node(linked_list_t **list, int index)
{
    linked_list_t *supressed = my_get_node(*list, index);
    linked_list_t *node1;
    linked_list_t *node2 = my_get_node(*list, index + 1);

    if (index == 0) {
        *list = node2;
    } else {
        node1 = my_get_node(*list, index - 1);
        node1->next = node2;
    }
    return supressed;
}
