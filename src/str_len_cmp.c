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