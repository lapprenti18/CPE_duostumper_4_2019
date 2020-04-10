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
    for (int temp = 0; temp < size + 2; temp ++) {
        tab[temp] = malloc(sizeof(char *) * (size + 3));
        if (tab[temp] == NULL)
            exit (84);
        tab[temp][size + 2] = '\0';
    }
    for (int temp = 0; temp < size + 2; temp ++) {
        for (int rep = 0; rep < size + 2; rep ++)
            tab[temp][rep] = ' ';
    }
    return (tab);
}

char **fill_tab(char **tab)
{
    for (int temp = 0; tab[temp]; temp ++) {
        for (int rep = 0; tab[temp][rep]; rep ++) {
            if (rep == 0 || tab[temp][rep + 1] == '\0')
                tab[temp][rep] = '|';
            if (temp == 0 || tab[temp + 1] == NULL)
                tab[temp][rep] = '+';
        }
    }
    return (tab);
}

void start_mixe(char **av, int size)
{
    char **tab = create_tab(size);

    tab = fill_tab(tab);
    for (int a = 0; tab[a]; a++)
        printf("%s\n", tab[a]);
    return;
}

int my_strlen(char *str)
{
    int length = 0;

    if (str == NULL)
        return (0);
    while (str[length] != '\0') {
        length += 1;
    }
    return (length);
}

int my_strcmp(char *one, char *two)
{
    int lenght_one = my_strlen(one);
    int lenght_two = my_strlen(two);

    if (lenght_one != lenght_two)
        return (1);
    for (int temp = 0; two[temp]; temp++) {
        if (two[temp] != one[temp])
            return (1);
    }
    return (0);
}

int main(int ac, char **av)
{
    int temp = 0;
    int size_square;

    if (ac < 5 || ac > 6)
        return (84);
    if (ac == 5) {
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