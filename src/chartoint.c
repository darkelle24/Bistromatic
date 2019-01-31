/*
** EPITECH PROJECT, 2018
** number.c
** File description:
** number.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bistro-matic.h"

int chartoint(char *nb)
{
    int result = 0;
    int size = my_strlen(nb);
    int a = 0;
    while(a <= (size-1)) {
        if (a == 0) {
            result = (nb[a] - 48) + result;
        }else{
            result = (nb[a] - 48) + result * 10;
        }
        a++;
    }
    return(result);
}