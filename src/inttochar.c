/*
** EPITECH PROJECT, 2018
** infinityadd
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bistro-matic.h"

char *inttochar(int nblist)
{
    int i = 0;
    int temp = nblist;
    char *nb;

    while (temp != 0) {
        temp = temp / 10;
        i++;
    }
    nb = malloc(sizeof(char)*i+1);
    nb[i] = '\0';
    i--;
    while (i >= 0) {
        nb[i] = nblist % 10 + 48;
        nblist = nblist / 10;
        i--;
    }
    return(nb);
}