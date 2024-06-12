/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-dorian.melenotte
** File description:
** executables.c
*/

#include "../my.h"
#include "printf.h"

char **parsing_path(char **env)
{
    char *path = NULL;
    char **parsed = NULL;
    int i = 0;

    while (env[i]) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
            && env[i][3] == 'H' && env[i][4] == '=')
            path = env[i];
        i++;
    }
    path += 5;
    parsed = my_str_to_double_array(path);
    if (parsed == NULL)
        parsed[0] = "/bin";
    return parsed;
}

char *create_path(char *first_half, char *second_half)
{
    int total_length = my_strlen(first_half) + my_strlen(second_half);
    char *str = malloc(sizeof(char) * (total_length + 1));

    str[0] = 0;
    my_strcat(str, first_half);
    my_strcat(str, second_half);
    str[total_length] = 0;
    return str;
}

static int my_exec(char *bin, char **arguments, char **env)
{
    int status = 0;
    pid_t pid = fork();

    switch (pid) {
        case -1:
            exit(84);
        case 0:
            if (execve(bin, arguments, env) == -1)
                exit(84);
        default:
            waitpid(pid, &status, 0);
            if (my_strcmp(arguments[0], "echo"))
                status = error_execution(status, arguments[1]);
    }
    return status;
}

int accessible(char *new_string, char **arguments, char **env)
{
    int exit_code = 0;

    if (!access(new_string, X_OK)) {
        exit_code = my_exec(new_string, arguments, env);
    } else {
        error_handler(new_string);
    }
    return exit_code;
}

static int executable_extention(char **arguments)
{
    if (arguments[0][0] == '.' && arguments[0][1] == '/' &&
    is_directory(arguments[0] + 2) == 1) {
        my_printf("%s: Permission denied.\n", arguments[0] + 2);
        return 1;
    }
    return 0;
}

int executable(char *argv, char **env, int exit_code)
{
    char **arguments = my_str_to_word_array(argv);
    char **parsing = parsing_path(env);
    char *new_string = 0;

    if (executable_extention(arguments))
        return 1;
    for (int i = 0; parsing[i]; i++) {
        new_string = create_path(parsing[i], arguments[0]);
        if (has_file(new_string)) {
            exit_code = accessible(new_string, arguments, env);
            return exit_code;
        }
        free(new_string);
    }
    if (has_file(arguments[0])) {
        exit_code = accessible(arguments[0], arguments, env);
        return exit_code;
    } else
        my_printf("%s: Command not found.\n", arguments[0]);
    return 1;
}
