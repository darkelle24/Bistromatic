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

char *modul(int number1 , int number2,char *av1,char *av2)
{
    int pass = 0;
    int i2 = 0;
    int i1 = 0;
    char **result;
    char **count;
    char nb = 0;

    count = malloc(sizeof(char *) * 2);
    count[0] = &nb;
    result = malloc(sizeof(char *) * 2);
    result[0] = av1;
    while (pass != -1) {
        pass = 0;
        number1 = my_strlen(result[0]);
        if (number1 < number2) {
            pass = -1;
        }else if(number1 == number2) {
            i2 = 0;
            i1 = 0;
            while (pass == 0 && result[0][i1] != '\0') {
                if (result[0][i1] > av2[i2]) {
                    pass = 1;
                }else if (result[0][i1] < av2[i2]) {
                    pass = -1;
                }
                i1++;
                i2++;
            }
        }
        if (pass != -1) {
            result = minusmain(result[0],av2,0,0);
            count = addmain(count[0],"1",0,0);
        }
    }
    result = multimain(count[0], av2,0,0);
    result = minusmain(av1,result[0],0,0);
    return(result[0]);
}

char **modulomain(char *nb1, char *nb2 ,int neg2)
{
    int neg = 0;
    int number1;
    int number2;
    char *finalnb;
    char **result;
    char nege = 0;

    result = malloc(sizeof(char *) * 2);
    result[1] = &nege;
    number1 = my_strlen(nb1);
    number2 = my_strlen(nb2);
    if (neg2 == 1) {
        result[1][0] = 1;
    }
    finalnb = malloc(sizeof(char) * (number1 + number2 + 1));
    neg = 0;
    while (neg <= (number1 + number2)) {
        finalnb[neg] = 48;
        neg++;
    }
    nege = result[1][0];
    result[0] = modul(number1 , number2,nb1,nb2);
    result[0] = reducar(result[0]);
    result[1][0] = nege;
    return (result);
}