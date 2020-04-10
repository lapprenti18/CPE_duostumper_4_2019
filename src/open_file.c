/*
** EPITECH PROJECT, 2019
** CPE_duo_2019
** File description:
** my.h
*/

#include "../my.h"

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