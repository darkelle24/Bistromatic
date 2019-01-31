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

char *reducar(char *nb)
{
    int i = 0;
    int pass = 0;
    int a = 0;
    char *result;

    while(nb[i] != '\0') {
        if (pass == 0 && nb[i] != 48) {
            pass = 1;
        }
        if (pass == 1) {
            a++;
        }
        i++;
    }
    if (a == 0) {
        a++;
    }
    result = malloc(sizeof(char) * a + 1);
    result[a] = '\0';
    i = 0;
    a = 0;
    pass = 0;
    while(nb[i] != '\0') {
        if (pass == 0 && nb[i] != 48) {
            pass = 1;
        }
        if (pass == 1) {
            result[a] = nb[i];
            a++;
        }
        i++;
    }
    if (a == 0) {
        result[0] = 48;
    }
    return(result);
}
