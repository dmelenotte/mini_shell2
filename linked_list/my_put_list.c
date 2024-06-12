/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-dorian.melenotte
** File description:
** my_putlist.c
*/

#include "../my.h"

void my_put_list(linked_list_t **list, char *key, char *value)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    node->key = key;
    if (value == NULL)
        node->value = "\0";
    else
        node->value = value;
    node->next = *list;
    *list = node;
}
