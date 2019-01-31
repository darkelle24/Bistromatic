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

int my_putstr(char const *str)
{
    while ( *str != '\0') {
	    write (1, str ,1);
	    str++;
    }
    return (0);
}

int charok(char test ,char *base ,char *signe)
{
    int sizesigne = my_strlen(signe);
    int sizebase = my_strlen(base);
    int a = 0;

    if (test ==  ' ') {
        return(1);
    }
    while (a < sizesigne) {
        if (signe[a] == test) {
            return(1);
        }
        a++;
    }
    a = 0;
    while (a < sizebase) {
        if (base[a] == test) {
            return(1);
        }
        a++;
    }
    return(0);
}

int gestionderreur(char *str ,char *base ,char *signe)
{
    int i = 0;
    int a = 0;
    int sizesigne = my_strlen(signe);
    int sizebase = my_strlen(base);
    int sizestr = my_strlen(str);
    int para = 0;

    if (sizesigne != 7)
        return(84);
    while (i < sizesigne) {
        a = 0;
        while (a < sizesigne) {
            if ((signe[a] == signe[i]) && a != i)
                return(84);
            a++;
        }
        i++;
    }
    i = 0;
    while (i < sizebase) {
        a = 0;
        while (a < sizebase) {
            if ((base[a] == base[i]) && a != i)
                return(84);
            a++;
        }
        i++;
    }
    a = 0;
    while (a < sizestr) {
        if (str[a] == signe[0]) {
            para++;
        } else if (str[a] == signe[1]) {
            para--;
        }
        if (para < 0)
            return(84);
        if (charok(str[a],base,signe) == 0)
            return(84);
        a++;
    }
    if (para != 0)
        return(84);
    return(0);
}

int main(int ac ,char **av)
{
    char *buffer;
    int charread = chartoint(av[3]);
    int error = 0;

    if (ac != 4 || charread <= 0) {
        my_putstr(SYNTAX_ERROR_MSG);
        return(84);
    }
    buffer = malloc(sizeof(char) * charread + 1);
    read(0,buffer,charread);
    buffer[charread] = '\0';
    error = gestionderreur(buffer,av[1],av[2]);
    if (error != 0) {
        if (error == 84) {
            my_putstr(SYNTAX_ERROR_MSG);
            return(84);
        } else {
            my_putstr(ERROR_MSG);
            return(84);
        }
        return(84);
    }else{
        error = eval_expr(buffer,av[1],av[2]);
    }
    return(0);
}