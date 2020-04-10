#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int my_putstr(char const *str);
 
void openfile(char const *filepath)
{
    int fdIn;
    int nbRead;
    char buffer[30000];
 
    fdIn = open(filepath, O_RDONLY, 0666);
 
    if (fdIn == -1) {
        my_putstr("Error opening file\n");
        exit(EXIT_FAILURE);
    }

    nbRead = read(fdIn, buffer, sizeof(buffer));
    while (nbRead > 0) {
        write(1, buffer, nbRead);
        nbRead = read(fdIn, buffer, sizeof(buffer));
    }

        close(fdIn);
}

