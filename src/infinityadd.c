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

char *minus(char *finalnb,char *nb1,char *nb2,int *nb)
{
    int i1 = nb[0] - 1;
    int i2 = nb[1] - 1;
    int result = 0;
    int retenue = 0;
    int i = 0;

    while (finalnb[i] != '\0') {
        i++;
    }
    while (i2 >= 0 || i1 >= 0) {
        if (i1 < 0) {
            result = (nb2[i2] - 48) - retenue;
        }else if (i2 < 0) {
            result = (nb1[i1] - 48) - retenue;
        }else{
            result = ((nb1[i1] - 48) - retenue) - (nb2[i2]-48);
        }
        if (result < 0) {
            retenue = 1;
            result = 10 - (result * -1);
        }else{
            retenue = 0;
        }
        finalnb[i] = result + 48;
        i--;
        i1--;
        i2--;
    }
    return(finalnb);
}

char *add(char *finalnb,char *nb1,char *nb2,int *nb)
{
    int i1 = nb[0] - 1;
    int i2 = nb[1] - 1;
    int result = 0;
    int retenue = 0;
    int i = 1;

    while (finalnb[i] != '\0') {
        i++;
    }
    while (i2 >= 0 || i1 >= 0) {
        if (i1 < 0) {
            result = (nb2[i2] - 48) + retenue;
        }else if (i2 < 0) {
            result = (nb1[i1] - 48) + retenue;
        }else{
            result = (nb1[i1] - 48) + (nb2[i2] - 48) + retenue;
        }
        if (result > 9) {
            retenue = 1;
            result = result - 10;
        }else{
            retenue = 0;
        }
        finalnb[i] = result + 48;
        i--;
        i1--;
        i2--;
    }
    if (retenue == 1) {
        finalnb[i] = 49;
    }
    return(finalnb);
}

char *separates(char *finalnb,char *nb1,char *nb2,int *nb) 
{
    int temp = 0;
    char *result;

    if (nb[2] == 3 || nb[2] == 0) {
        result = add(finalnb,nb1,nb2,&nb[0]);
    }
    if (nb[2] == 4 || nb[2] == 7) {
        result = minus(finalnb,nb1,nb2,&nb[0]);
    }
    if (nb[2] == 5 || nb[2] == 6) {
        temp = nb[0];
        nb[0] = nb[1];
        nb[1] = temp;
        result = minus(finalnb,nb2,nb1,&nb[0]);
    }
    return(result);
}

char **arraycreate(int nbtotal, int plus , int neg,char **result)
{
    char *finalnb;
    int i = 0;
    char nega = 1;

    finalnb = malloc(sizeof(char)*nbtotal + plus +1);
    while (i < (nbtotal + plus -1)) {
        finalnb[i] = 48;
        i++;
    }
    finalnb[nbtotal + plus -1] = '\0';
    if (neg == 1) {
        result[1] = &nega;
    }
    result[0] = finalnb;
    return(result);
}

char **addmain(char *nb1, char *nb2 ,int neg1 ,int neg2)
{
    int neg = 0;
    int number1 = 0;
    int number2 = 0;
    int i1 = 0;
    int i2 = 0;
    int nb[3];
    int pass = 0;
    char **results;
    char nega = 0;


    results = malloc(sizeof(char *) * 2);
    results[1] = &nega;
    if (neg1 == 1)
        neg++;
    if (neg2 == 1)
        neg++;
    number1 = my_strlen(nb1);
    number2 = my_strlen(nb2);
    if (neg == 2) {
        if (number1 > number2) {
            results = arraycreate(number1,1,1,results);
        } else {
            results = arraycreate(number2,1,1,results);
        }
        neg = 3;
    }
    if (neg == 1) {
        if (neg1 == 1) {
            if ((number1) > number2) {
                results = arraycreate(number1,0,1,results);
                neg = 4;
            }else if ((number1 - 1) < number2) {
                results = arraycreate(number2,0,0,results);
                neg = 5;
            }else{
                i1++;
            }
        }else{
            if ((number2 - 1) > number1) {
                results = arraycreate(number2,1,1,results);
                neg = 6;
            }else if ((number2 - 1) < number1)  {
                results = arraycreate(number1,0,0,results);
                neg = 7;
            }else{
                i2++;
            }
            neg = 2;
        }
        while (pass == 0 && (neg == 2 || neg == 1)) {
            if (nb1[i1] > nb2[i2]) {
                pass = 1;
            }else if (nb1[i1] < nb2[i2]) {
                pass = -1;
            }
            i1++;
            i2++;
        }
        if (pass == 1 && neg == 1) {
            results = arraycreate(number1,2,1,results);
            neg = 4;
        }else if (pass == 1 && neg == 2) {
            results = arraycreate(number1,1,0,results);
            neg = 5;
        }
        if (pass == -1 && neg == 2) {
            results = arraycreate(number2,2,1,results);
            neg = 6;
        }else if (pass == -1 && neg == 1) {
            results = arraycreate(number2,1,0,results);
            neg = 7;
        }
    }
    if (neg == 0 && number1 >= number2) {
        results = arraycreate(number1,1,0,results);
    } else if (neg == 0 && number2 > number1) {
        results = arraycreate(number2,1,0,results);
    }
    nb[0] = number1;
    nb[1] = number2;
    nb[2] = neg;
    pass = results[1][0];
    results[0] = separates(results[0],nb1,nb2,&nb[0]);
    results[0] = reducar(results[0]);
    results[1][0] = pass;
    return(results);
}