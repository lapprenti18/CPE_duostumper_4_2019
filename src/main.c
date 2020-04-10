/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** my.h
*/

#include "../my.h"

int nb_word_two(char **tab_db)
{
    int count = 0;

    for (; tab_db[count]; count++);
    return (count);
}

void print_all(char **tab, int word_enter, char **tab_db)
{
    int err = 0;
    int count_word = nb_word_two(tab_db);

    for (int temp = 0; tab[temp]; temp++) {
        for (int rep = 0; tab[temp][rep]; rep++) {
            tab[temp][rep] == ' ' ? tab[temp][rep] = 'a' : 0;
        }
    }
    err = printf ("%d/%d words inserted in the grid.\n", word_enter, count_word);
    if (err == -1)
        exit (84);
    for (int temp = 0; tab[temp]; temp++) {
        err = printf("%s\n", tab[temp]);
        if (err == -1)
            exit (84);
        free(tab[temp]);
    }
    free(tab);
}

void word_in_tab(char **tab, char **tab_db)
{
    int word_enter = 0;
    int bool = 0;
    int rep = 0;

    for (int temp = 1; tab[temp + 1]; temp++) {
        if (tab_db[temp - 1] == NULL)
            break;
        bool = 0;
        for (rep = 0; tab[temp][rep] && bool != 1; rep++) {
            if (tab[temp][rep] != '|') {
                (tab_db[temp - 1][rep] == '\0') ? bool = 1 : 0;
                (tab_db[temp - 1][rep] != '\0') ? tab[temp][rep] = tab_db\
                [temp - 1][rep - 1] : 0;
            }
        }
        rep = rep - 1;
        tab[temp][rep] = tab_db[temp - 1][rep - 1];
        if (bool == 1)
            word_enter += 1;
    }
    print_all(tab, word_enter, tab_db);
}

void start_mixe(char **av, int size)
{
    int temp = 0;
    char **tab = create_tab(size);
    char *db;
    char **tab_db;

    tab = fill_tab(tab);
    for (; av[temp + 1]; temp++) {
        if (my_strcmp(av[temp], "-f") == 0) {
            db = open_file(av[temp + 1]);
            break;
        }
    }
    if (temp == 5 || (size == 8 && temp == 4))
        exit (84);
    tab_db = my_str_to_word_array(db);
    word_in_tab(tab, tab_db);
    return;
}

int main(int ac, char **av)
{
    int temp = 0;
    int size_square;

    if (ac < 4 || ac > 5)
        return (84);
    if (ac == 4) {
        start_mixe(av, 8);
        return (0);
    }
    for (; av[temp + 1]; temp++) {
        if (my_strcmp(av[temp], "-s") == 0) {
            size_square = atoi(av[temp + 1]);
            start_mixe(av, size_square);
            return (0);
        }
    }
    return (84);
}