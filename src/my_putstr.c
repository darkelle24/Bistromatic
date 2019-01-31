/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** Task02
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/bistro-matic.h"

int my_putstrreverse(char const *str)
{
    int lenght = my_strlen(str);

    lenght--;
    while ( lenght >= 0)
    {
	write (1, &str[lenght] ,1);
	lenght--;
    }
    return (0);
}
