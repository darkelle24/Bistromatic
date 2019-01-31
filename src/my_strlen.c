/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** return the lenght of a string
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bistro-matic.h"

int my_strlen(char const *str)
{
    int nbchar;

    nbchar = 0;
    while (*str != '\0') {
        nbchar++;
        str++;
    }
    return (nbchar);
}
