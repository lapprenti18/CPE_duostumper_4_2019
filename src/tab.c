/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** my.h
*/

#include "../my.h"

char **create_tab(int size)
{
    char **tab = malloc(sizeof(char *) * (size + 3));

    if (tab == NULL)
        exit (84);
    tab[size + 2] = NULL;
    for (int temp = 0; temp < size + 2; temp++) {
        tab[temp] = malloc(sizeof(char *) * (size + 3));
        if (tab[temp] == NULL)
            exit (84);
        tab[temp][size + 2] = '\0';
    }
    for (int temp = 0; temp < size + 2; temp++) {
        for (int rep = 0; rep < size + 2; rep++)
            tab[temp][rep] = ' ';
    }
    return (tab);
}

char **fill_tab(char **tab)
{
    for (int temp = 0; tab[temp]; temp++) {
        for (int rep = 0; tab[temp][rep]; rep++) {
            if (rep == 0 || tab[temp][rep + 1] == '\0')
                tab[temp][rep] = '|';
            if (temp == 0 || tab[temp + 1] == NULL)
                tab[temp][rep] = '+';
        }
    }
    return (tab);
}