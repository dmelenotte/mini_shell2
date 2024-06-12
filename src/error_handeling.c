/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-dorian.melenotte
** File description:
** error_handeling.c
*/

#include "../my.h"
#include "printf.h"

int error_handler(char *cmd)
{
    if (!is_directory(cmd) && errno == ENOEXEC) {
        my_putstr2(cmd);
        my_putstr2(": Exec format error. Wrong Architecture.\n");
        return (1);
    }
    if (errno == EACCES || errno == EPERM) {
        if (!is_directory(cmd)) {
            my_putstr2(cmd);
            my_putstr2(": Permission denied.\n");
            return (1);
        }
    }
    return 0;
}

int error_execution(int status, char *cmd)
{
    if (error_handler(cmd))
        return 1;
    if (WIFEXITED(status))
        return WEXITSTATUS(status);
    if (status == 139) {
        my_putstr2("Segmentation fault\n");
        return 139;
    }
    if (status == 136) {
        my_putstr2("Flowting point exeption\n");
        return 136;
    }
    if (WIFSIGNALED(status))
        status = WTERMSIG(status);
    if (status == SIGSEGV) {
        my_putstr2("Segmentation fault\n");
        return 139;
    }
    return status;
}
