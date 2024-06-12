/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-dorian.melenotte
** File description:
** bluilt_in.c
*/

#include "../my.h"
#include "printf.h"

int count_elem(char **str)
{
    int i = 0;

    while (str[i]) {
        i++;
    }
    return i;
}

char *get_in_env(linked_list_t **list_env, char *str)
{
    linked_list_t *tmp = *list_env;
    char *actual;

    for (; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->key, str)){
            actual = tmp->value;
            return actual;
        }
    }
    return NULL;
}

char *refresh_pwd(linked_list_t **list_env)
{
    linked_list_t *tmp = *list_env;
    int i = 0;
    char *previus;

    for (; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->key, "PWD")){
            getcwd(tmp->value, 1000);
            previus = tmp->value;
            setenv_scan(list_env, "PWD", previus);
            return previus;
        }
        i++;
    }
    return NULL;
}

static void my_unsetenv(linked_list_t **list, char *str)
{
    linked_list_t *tmp = *list;
    int i = 0;

    for (i = 0; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->key, str)){
            my_delete_node(list, i);
        }
        i++;
    }
}

int setenv_scan(linked_list_t **list_env, char *str, char *cmd)
{
    linked_list_t *tmp = *list_env;

    for (; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->key, str)){
            tmp->value = cmd;
            return 1;
        }
    }
    return 0;
}

static int is_alpha(char **arg)
{
    if (!((arg[1][0] >= 'a' && arg[1][0] <= 'z') ||
    (arg[1][0] >= 'A' && arg[1][0] <= 'Z') || arg[1][0] == '_')) {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int j = 1; arg[1][j]; j++) {
        if (!((arg[1][j] >= 'a' && arg[1][j] <= 'z') ||
        (arg[1][j] >= 'A' && arg[1][j] <= 'Z') ||
        (arg[1][j] >= '0' && arg[1][j] <= '9') || arg[1][j] == '_')) {
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}

static int setenv_extention(char **argument, linked_list_t **list_env)
{
    if (count_elem(argument) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 0;
    }
    if (count_elem(argument) == 2 && !setenv_scan(list_env,
    argument[1], "\0")) {
        my_put_list(list_env, argument[1], NULL);
        return 1;
    }
    if (count_elem(argument) == 3 && !setenv_scan(list_env,
    argument[1], argument[2])) {
        my_put_list(list_env, argument[1], argument[2]);
        return 1;
    }
    return 0;
}

static int setunsetenv(char **argument, linked_list_t **list_env)
{
    if ((!my_strcmp(argument[0], "setenv") && count_elem(argument) < 4) &&
    is_alpha(argument)) {
        if (setenv_extention(argument, list_env))
            return 1;
    }
    if (!my_strcmp(argument[0], "unsetenv")) {
        for (int i = 1; argument[i]; i++)
            my_unsetenv(list_env, argument[i]);
        return 1;
    }
    return 1;
}

int bluilt_in(linked_list_t **list_env, char *argv)
{
    char **arguments = my_str_to_word_array(argv);

    if (!my_strcmp(arguments[0], "env") && count_elem(arguments) < 2) {
        display_env(*list_env);
        return 1;
    }
    if ((!my_strcmp(arguments[0], "cd"))) {
        my_cd(arguments, list_env);
        return 1;
    }
    if ((!my_strcmp(arguments[0], "setenv") ||
        !my_strcmp(arguments[0], "unsetenv"))) {
        if (count_elem(arguments) == 1) {
            display_env(*list_env);
            return 1;
        }
        return setunsetenv(arguments, list_env);
    }
    return 0;
}
