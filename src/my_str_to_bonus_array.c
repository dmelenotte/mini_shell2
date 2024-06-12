/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-dorian.melenotte
** File description:
** my_str_to_semicolon_array.c
*/

#include "../my.h"
#include "printf.h"

static int count_elements(char *str)
{
    int count = 0;

    for (; *str; str++)
        count += (*str == '>' && *(str + 1) != '>');
    return count + (*(str - 1) != '>');
}

static int my_countstr(char *str)
{
    int count = 0;

    while (*str && !(*str == '>' && *(str + 1) != '>')) {
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

char **my_str_to_bonus_array(char *str)
{
    int elements = count_elements(str);
    char **map = malloc(sizeof(char *) * (elements + 1));
    char *str_enter = NULL;
    int index = 0;

    str = jump_to_next_element(str);
    for (int index2 = 0; *str; index2++) {
        index = 0;
        str_enter = malloc(sizeof(char) * (my_countstr(str) + 1));
        for (; !(*str == '>' && *(str + 1) != '>') && *str; str++) {
            str_enter[index] = *str;
            index++;
        }
        str_enter[index] = '\0';
        map[index2] = str_enter;
        str += (*str == '>' && *(str + 1) != '>') ? 1 : 0;
        str = jump_to_next_element(str);
    }
    map[elements] = 0;
    return map;
}
