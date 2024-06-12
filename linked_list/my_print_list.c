/*
** EPITECH PROJECT, 2023
** B-CPE-110-TLS-1-1-organized-dorian.melenotte
** File description:
** my_putlist.c
*/

#include "../my.h"
#include "printf.h"

void my_print_list(linked_list_t *list)
{
    linked_list_t *tmp = list;

    while (tmp) {
        my_printf("%s%s\n", tmp->key, tmp->value);
        tmp = tmp->next;
    }
}
