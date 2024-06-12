/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-dorian.melenotte
** File description:
** utils.c
*/

#include "../my.h"
#include "printf.h"

int str_has_letter(char **tab, int i, char lettre, int elem)
{
    for (int j = 0; tab[i][j] != tab[elem][my_strlen(tab[elem]) - 3]; j++) {
        if (tab[i][j] == lettre)
            return 1;
    }
    return 0;
}

int has_int_it(char **tab, char lettre, int elem)
{
    for (int i = 1; tab[i] != NULL; i++) {
        if (str_has_letter(tab, i, lettre, elem))
            return 1;
    }
    return 0;
}

int has_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return 0;
    close(fd);
    return 1;
}

int is_directory(char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    if (S_ISDIR(path_stat.st_mode)) {
        return 1;
    } else if (S_ISREG(path_stat.st_mode)) {
        return 0;
    } else {
        return -1;
    }
}
