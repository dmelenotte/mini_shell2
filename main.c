/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-bsminishell1-dorian.melenotte
** File description:
** main.c
*/

#include "my.h"
#include "printf.h"

static int is_double_redirection(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '>')
            count++;
    }
    if (count == 2)
        return 1;
    return 0;
}

static int has_double_redirection(char **cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (is_double_redirection(cmd[i]))
            return 1;
    }
    return 0;
}

static int is_redirection(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '>')
            count++;
    }
    if (count == 1)
        return 1;
    return 0;
}

static int has_redirection(char **cmd)
{
    for (int i = 0; cmd[i]; i++) {
        if (is_redirection(cmd[i]))
            return 1;
    }
    return 0;
}

int pars_cmd(char **cmd, int i, char **env, linked_list_t **list_env)
{
    int exit_with = 0;

    if (my_strcmp(cmd[i], "exit") == 0){
        my_printf("exit\n");
        exit(0);
    }
    if (has_redirection(cmd)) {
        exit_with = my_redirection(cmd, i, env);
        return exit_with;
    }
    if (has_double_redirection(cmd)) {
        exit_with = my_double_redirection(cmd, i, env);
        return exit_with;
    }
    if (exit_with != -1 && !bluilt_in(list_env, cmd[i])) {
        exit_with = executable(cmd[i], env, exit_with);
    }
    free(cmd[i]);
    return exit_with;
}

int launch_minishell(linked_list_t *list_env, char **env)
{
    char *line = NULL;
    long unsigned int len = 0;
    char **cmd = NULL;
    int exit_with = 0;

    while (1) {
        if (isatty(0))
            my_printf("$> ");
        if (getline(&line, &len, stdin) == -1)
            exit(exit_with);
        line[my_strlen(line) - 1] = '\0';
        if (line[0] == '\0')
            continue;
        cmd = my_str_to_semicolon_array(line);
        for (int i = 0; cmd[i]; i++) {
            exit_with = pars_cmd(cmd, i, env, &list_env);
        }
    }
    return exit_with;
}

int main(int argc, char **argv, char **env)
{
    linked_list_t *list_env = NULL;

    error_handler(argv[0]);
    if (env == NULL)
        return 84;
    list_env = create_environement(&list_env, env);
    if (argc > 1)
        return 84;
    return launch_minishell(list_env, env);
}
