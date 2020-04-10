/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** my.h
*/

#include "../my.h"

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

char *open_file(char *str)
{
    int fd = open(str, O_RDONLY);
    struct stat size_buff;
    char *buffer;
    int err;

    if (fd == -1)
        exit (84);
    err = stat(str, &size_buff);
    if (size_buff.st_size == 0 || err == -1)
        exit (84);
    buffer = malloc(sizeof(char) * size_buff.st_size + 1);
    if (buffer == NULL)
        exit (84);
    buffer[size_buff.st_size] = '\0';
    err = read(fd, buffer, size_buff.st_size);
    if (err == -1)
        exit (84);
    return (buffer);
}

int nb_word_two(char **tab_db)
{
    int count = 0;

    for (; tab_db[count]; count++);
    return (count);
}

void print_all(char **tab, int word_enter, int count_word)
{
    int err = 0;

    err = printf ("%d/%d words inserted in the grid.\n", word_enter, count_word);
    if (err == -1)
        exit (84);
    for (int temp = 0; tab[temp]; temp ++) {
        err = printf("%s\n", tab[temp]);
        if (err == -1)
            exit (84);
    }
}
void word_in_tab(char **tab, char *db)
{
    char **tab_db = my_str_to_word_array(db);
    int count_word = nb_word_two(tab_db);
    int word_enter = 0;
    int bool = 0;
    int rep = 0;

    for (int temp = 1; tab[temp + 1]; temp ++) {
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
    print_all(tab, word_enter, count_word);
}

void start_mixe(char **av, int size)
{
    int temp = 0;
    char **tab = create_tab(size);
    char *db;

    tab = fill_tab(tab);
    for (; av[temp + 1]; temp++) {
        if (my_strcmp(av[temp], "-f") == 0) {
            db = open_file(av[temp + 1]);
            break;
        }
    }
    if (temp == 5 || (size == 8 && temp == 4))
        exit (84);
    word_in_tab(tab, db);
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