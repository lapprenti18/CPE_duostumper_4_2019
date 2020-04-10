/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** str_to_word_array
*/

#include "../my.h"

int nb_word(char *str)
{
    int word = 0;
    int rep;

    for (rep = 0; str[rep]; rep += 1) {
        if (str[rep] == '\0' || str[rep] == '\n')
            word += 1;
    }
    return (word);
}

int word_lenght(char *str, int rep_str)
{
    int lenght = 0;

    for (; str[rep_str]; rep_str += 1) {
        if (str[rep_str] == '\n')
            break;
        lenght += 1;
    }
    return (lenght);
}

char **my_str_to_word_array(char *str)
{
    char **tab = malloc(sizeof(char *) * (nb_word(str) + 1));
    int rep_str = 0;
    int lenght_word = 0;
    int rep = 0;

    if (tab == NULL)
        return (tab);
    tab[nb_word(str)] = NULL;
    for (int rep_tab = 0; rep_tab < nb_word(str); rep_tab += 1) {
        lenght_word = word_lenght(str, rep_str);
        tab[rep_tab] = malloc(sizeof(char) * (lenght_word + 1));
        if (tab[rep_tab] == NULL)
            return (tab);
        tab[rep_tab][lenght_word] = '\0';
        for (rep = 0; rep < lenght_word; rep += 1) {
            tab[rep_tab][rep] = str[rep_str];
            rep_str += 1;
        }
        rep_str += 1;
    }
    return (tab);
}