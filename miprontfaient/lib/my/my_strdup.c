/*
** EPITECH PROJECT, 2023
** day08
** File description:
** my_strdup.c
*/

#include "my.h"

char *my_strdup(const char *src)
{
    char *dest = malloc(sizeof(char) *(my_strlen(src) + 1));

    return my_strcpy(dest, src);
}
