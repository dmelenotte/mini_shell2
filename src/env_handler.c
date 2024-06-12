/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-minishell1-dorian.melenotte
** File description:
** env_handler
*/

#include "../my.h"
#include "printf.h"

void display_env(linked_list_t *env)
{
    linked_list_t *copy = env;

    if (!copy)
        return;
    display_env(copy->next);
    my_printf("%s=%s\n", copy->key, copy->value);
}

static char *trim_string(char *str, int start, int end)
{
    int len = end - start + 1;
    char *new_str = malloc(sizeof(char) * (len + 1));
    int index = 0;

    for (int i = start; i < end; i++) {
        new_str[index] = str[i];
        index++;
    }
    new_str[len] = 0;
    return new_str;
}

static char **parse_key_value(char *str)
{
    int i = 0;
    char **key_value = malloc(sizeof(char *) * 3);

    while (str[i] && str[i] != '=')
        i++;
    if (str[i] != '=')
        return 0;
    key_value[0] = trim_string(str, 0, i);
    key_value[1] = str + i + 1;
    key_value[2] = 0;
    return key_value;
}

linked_list_t *create_environement(linked_list_t **env_list, char **env)
{
    char *key = 0;
    char *value = 0;
    char **str = 0;

    for (int i = 0; env[i]; i++) {
        str = parse_key_value(env[i]);
        if (!str)
            exit(84);
        key = str[0];
        value = str[1];
        my_put_list(env_list, key, value);
    }
    return *env_list;
}
