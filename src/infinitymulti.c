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

char *multi(int number1 , int number2 ,char *finalnb,char *av1,char *av2) 
{
    int i = number2 - 1;
    int b = number1 - 1;
    int total = number1 + number2;
    int result = 0;
    int retenue = 0;

    while (i >= 0) {
        b = number1 - 1;
        retenue = 0;
        while (b >= 0) {
            result = (av1[b]-48) * (av2[i]-48);
            retenue = result / 10;
            if (result > 9 ) {
                result = result + (finalnb[total-(number2 - i-1)-(number1 - b - 1)] - 48);
                if (result > 9) {
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)] = result % 10 + 48;
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)-1] = result / 10 +(finalnb[total-(number2 - i-1)-(number1 - b - 1)-1] - 48) + 48;
                }else{
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)] = result + 48;
                }
            }else{
                result = (result % 10) + (finalnb[total-(number2 - i-1)-(number1 - b - 1)] - 48);
                 if (result > 9) {
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)] = result % 10 + 48;
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)-1] = result / 10 +(finalnb[total-(number2 - i-1)-(number1 - b - 1)-1] - 48) + 48;
                }else{
                    finalnb[total-(number2 - i-1)-(number1 - b - 1)] = result + 48;
                }
                retenue = 0;    
            }
            b--;
        }
        if (retenue != 0 && av1[b] == '\0') {
            b--;
            finalnb[b-((number2 - 1) - i)+1] = retenue + (finalnb[b-((number2 - 1) - i)+1] - 48)+ 48;
        }
        i--;
    }
    return(&finalnb[0]);
}

char **multimain(char *nb1, char *nb2 ,int neg1 ,int neg2)
{
    int neg = 0;
    int number1;
    int number2;
    char *finalnb;
    char **result;
    char nege = 0;

    result = malloc(sizeof(char *) * 2);
    result[1] = &nege;
    if (neg1 == 1)
        neg++;
    if (neg2 == 1)
        neg++;
    number1 = my_strlen(nb1);
    number2 = my_strlen(nb2);
    if (neg == 1) {
        result[1][0] = 1;
    }
    finalnb = malloc(sizeof(char) * (number1 + number2 + 1));
    neg = 0;
    while (neg <= (number1 + number2)) {
        finalnb[neg] = 48;
        neg++;
    }
    nege = result[1][0];
    if (number2 > number1) {
        result[0] = multi(number2,number1,finalnb,nb2,nb1);
    }else{
        result[0] = multi(number1 , number2,finalnb,nb1,nb2);
    }
    result[0] = reducar(result[0]);
    result[1][0] = nege;
    return (result);
}