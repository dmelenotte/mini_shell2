/*
** EPITECH PROJECT, 2022
** my
** File description:
** h
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY
    #define MY

typedef struct linked_list {
    char *key;
    char *value;
    struct linked_list *next;
} linked_list_t;

int bluilt_in(linked_list_t **list_env, char *argv);
int executable(char *argv, char **env, int exit_code);
char **my_str_to_double_array(char *str);
void execute_error_handling(char *cmd);
int my_putstr2(char const *str);
int error_execution(int status, char *cmd);
void display_env(linked_list_t *env);
char **my_str_to_slash_array(char *str);
int count_elem(char **str);
int is_directory(char *path);
int setenv_scan(linked_list_t **list_env, char *str, char *cmd);
char *get_in_env(linked_list_t **list_env, char *str);
void my_cd(char **args, linked_list_t **list_env);
char *refresh_pwd(linked_list_t **list_env);
int has_file(char *path);
int has_int_it(char **tab, char lettre, int elem);
char **my_str_to_semicolon_array(char *str);
int accessible(char *new_string, char **arguments, char **env);
char *create_path(char *first_half, char *second_half);
char **parsing_path(char **env);
int my_redirection(char **cmd, int i, char **env);
char **my_str_to_bonus_array(char *str);
int my_double_redirection(char **cmd, int i, char **env);

//linked list
void my_print_list(linked_list_t *list);
void my_put_list(linked_list_t **list, char *name, char *commande);
linked_list_t *my_get_node(linked_list_t *list, int index);
linked_list_t *create_environement(linked_list_t **env_list, char **env);
linked_list_t *my_delete_node(linked_list_t **list, int index);

#endif
