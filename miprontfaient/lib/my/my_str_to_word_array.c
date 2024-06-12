/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_str_to_word_array
*/

#include "my.h"

static int count_elements(char *str)
{
    int count = 0;

    for (; *str; str++)
        count += (*str == 32 || *str == '\t');
    return count + (*(str - 1) != 32);
}

static int my_countstr(char *str)
{
    int count = 0;

    while (*str && (*str != 32 || *str != '\t')) {
        count++;
        str++;
    }
    return count;
}

static char *jump_to_next_element(char *str)
{
    while (*str == 32 || *str == '\t')
        str++;
    return str;
}

char **my_str_to_word_array(char *str)
{
    int elements = count_elements(str);
    char **map = malloc(sizeof(char *) * (elements + 1));
    char *str_enter = 0;
    int index = 0;

    str = jump_to_next_element(str);
    for (int index2 = 0; *str; index2++) {
        index = 0;
        str_enter = malloc(sizeof(char) * (my_countstr(str) + 1));
        for (; *str && *str != 32; str++) {
            str_enter[index] = *str;
            index++;
        }
        str_enter[index] = 0;
        map[index2] = str_enter;
        str += (*str != 0);
        str = jump_to_next_element(str);
    }
    map[elements] = 0;
    return map;
}
