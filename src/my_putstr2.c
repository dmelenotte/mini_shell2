/*
** EPITECH PROJECT, 2023
** day04
** File description:
** my_putstr.c
*/

#include "../my.h"
#include "printf.h"

int my_putchar2(char c)
{
    write(2, &c, 1);
    return 1;
}

int my_putstr2(char const *str)
{
    int i = 0;

    while (str[i] != 0) {
        my_putchar2(str[i]);
        i++;
    }
    return my_strlen(str);
}
