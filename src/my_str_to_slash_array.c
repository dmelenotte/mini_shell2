/*
** EPITECH PROJECT, 2023
** day08
** File description:
** my_str_to_word_array.c
*/

#include "../my.h"
#include "printf.h"

static int count_elements(char *str)
{
    int count = 0;

    for (; *str; str++)
        count += (*str == '/');
    return count + (*(str - 1) != '/');
}

static int my_countstr(char *str)
{
    int count = 0;

    while (*str && *str != '/') {
        count++;
        str++;
    }
    return count;
}

char **my_str_to_slash_array(char *str)
{
    int elements = count_elements(str);
    char **map = malloc(sizeof(char *) * (elements + 1));
    char *str_enter = 0;
    int index = 0;

    for (int index2 = 0; *str; index2++) {
        index = 0;
        str_enter = malloc(sizeof(char) * (my_countstr(str) + 2));
        for (; *str && *str != '/'; str++) {
            str_enter[index] = *str;
            index++;
        }
        str_enter[index] = 0;
        map[index2] = str_enter;
        str += (*str != 0);
    }
    map[elements] = 0;
    return map;
}
