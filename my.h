/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** my.h
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

char **my_str_to_word_array(char *str);
char *open_file(char *str);
int my_strlen(char *str);
int my_strcmp(char *one, char *two);
char **create_tab(int size);
char **fill_tab(char **tab);
int nb_word_two(char **tab_db);
void print_all(char **tab, int word_enter, char **tab_db);
void word_in_tab(char **tab, char **tab_db);
void start_mixe(char **av, int size);