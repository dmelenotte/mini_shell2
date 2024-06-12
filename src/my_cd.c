/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-dorian.melenotte
** File description:
** my_cd.c
*/

#include "../my.h"
#include "printf.h"

int classic_cd(char **args, linked_list_t **list_env)
{
    if (!my_strcmp(args[1], "/root"))
        my_printf("/root: Permission denied.\n");
    if (is_directory(args[1]) == 0)
        my_printf("%s: Not a directory.\n", args[1]);
    else if (count_elem(args) == 2 && my_strcmp(args[1], "~") &&
    my_strcmp(args[1], "-")) {
        refresh_pwd(list_env);
        chdir(args[1]);
        return 1;
    }
    return 0;
}

void my_cd_next(char **args, linked_list_t **list_env, char *path)
{
    char *str = get_in_env(list_env, "OLDPWD");

    if (count_elem(args) < 2 || (count_elem(args) == 2 &&
    !my_strncmp(args[1], "~", 1))) {
        refresh_pwd(list_env);
        setenv_scan(list_env, "OLDPWD", path);
        chdir(path);
        return;
    }
    if (classic_cd(args, list_env))
        return;
    if (count_elem(args) == 2 && !my_strcmp(args[1], "-")) {
        setenv_scan(list_env, "OLDPWD", get_in_env(list_env, "PWD"));
        chdir(get_in_env(list_env, "PWD"));
        setenv_scan(list_env, "PWD", str);
        return;
    }
    my_printf("%s: No such file or directory.\n", args[1]);
    return;
}

void my_cd(char **args, linked_list_t **list_env)
{
    linked_list_t *tmp = *list_env;
    char *path = 0;

    for (; tmp; tmp = tmp->next) {
        if (!my_strcmp(tmp->key, "HOME"))
            path = tmp->value;
    }
    my_cd_next(args, list_env, path);
}
