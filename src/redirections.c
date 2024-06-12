/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-dorian.melenotte
** File description:
** redirections.c
*/

#include "../my.h"
#include "printf.h"

int my_double_redirection(char **cmd, int i, char **env)
{
    int fd = 0;
    char **pars_cmd = my_str_to_bonus_array(cmd[i]);
    int fd_copy = 0;
    int j = 0;

    pars_cmd[0][my_strlen(pars_cmd[0]) - 1] = '\0';
    fd = open(pars_cmd[1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    fd_copy = dup(1);
    if (dup2(fd, 1) == -1) {
        perror("error_dup2");
        return -1;
    }
    executable(pars_cmd[0], env, 0);
    dup2(fd_copy, 1);
    close(fd);
    return 0;
}

int my_redirection(char **cmd, int i, char **env)
{
    int fd = 0;
    char **pars_cmd = my_str_to_bonus_array(cmd[i]);
    int fd_copy = 0;
    int j = 0;

    fd = open(pars_cmd[1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    fd_copy = dup(1);
    if (dup2(fd, 1) == -1) {
        perror("error_dup2");
        return -1;
    }
    executable(pars_cmd[0], env, 0);
    dup2(fd_copy, 1);
    close(fd);
    return 0;
}

int my_left_redirection(char **cmd, int i, char **env)
{
    char **pars_cmd = my_str_to_word_array(cmd[i]);

    return 0;
}
