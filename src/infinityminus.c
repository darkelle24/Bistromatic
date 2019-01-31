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

char *separates2(char *finalnb,char *nb1,char *nb2,int *nb) 
{
    int temp = 0;
    char *result;

    if (nb[2] == 8) {
        result = add(finalnb,nb1,nb2,&nb[0]);
    }
    if (nb[2] == 4) {
        result = minus(finalnb,nb1,nb2,&nb[0]);
    }
    if (nb[2] == 5) {
        temp = nb[0];
        nb[0] = nb[1];
        nb[1] = temp;
        result = minus(finalnb,nb2,nb1,&nb[0]);
    }
    if (nb[2] == 10) {
        result = minus(finalnb,nb1,nb2,&nb[0]);
    }
    if (nb[2] == 9) {
        temp = nb[0];
        nb[0] = nb[1];
        nb[1] = temp;
        result = minus(finalnb,nb2,nb1,&nb[0]);
    }
    return(result);
}

char **minusmain(char *nb1, char *nb2 ,int neg1 ,int neg2)
{
    int neg = 0;
    int number1 = 0;
    int number2 = 0;
    int i = 0;
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
    if (neg == 1) {
        if (neg2 == 1 && number1 >= number2) {
            results = arraycreate(number1,1,0,results);
            neg = 8;
        }else if (neg2 == 1 && number1 < number2) {
            results = arraycreate(number2,1,0,results);
            neg = 8;
        }
        if (neg1 == 1 && number1 >= number2) {
            results = arraycreate(number1,1,1,results);
            neg = 8;
        }else if (neg1 == 1 && number1 < number2) {
            results = arraycreate(number2,1,1,results);
            neg = 8;
        }
    }
    if (neg == 2) {
       if (number1 > number2) {
            results = arraycreate(number1,1,1,results);
            neg = 10;
        } else if (number2 > number1) {
            results = arraycreate(number2,1,0,results);
            neg = 9;
        }else{
            while (pass == 0 && i < number1) {
                if (nb1[i] > nb2[i]) {
                    pass = 1;
                }else if (nb1[i] < nb2[i]) {
                    pass = -1;
                }
                i++;
            }
            if (pass == -1) {
                results = arraycreate(number2,1,0,results);
                neg = 9;
            } else if (pass == 1) {
                results = arraycreate(number1,1,1,results);
                neg = 10;
            }else{
                results = arraycreate(1,0,0,results);
                neg = 11;
            }
        }
    }
    if (neg == 0) {
        if (number1 > number2) {
            results = arraycreate(number1,1,0,results);
            neg = 4;
        } else if (number2 > number1) {
            results = arraycreate(number2,1,1,results);
            neg = 5;
        }else{
            while (pass == 0 && i < number1) {
                if (nb1[i] > nb2[i]) {
                    pass = 1;
                }else if (nb1[i] < nb2[i]) {
                    pass = -1;
                }
                i++;
            }
            if (pass == -1) {
                results = arraycreate(number1,1,1,results);
                neg = 5;
            } else if (pass == 1) {
                results = arraycreate(number2,1,0,results);
                neg = 4;
            }else{
                results = arraycreate(1,0,0,results);
                neg = 11;
            }
        }
    }
    nb[0] = number1;
    nb[1] = number2;
    nb[2] = neg;
    pass = results[1][0];
    if (neg != 11) {
        results[0] = separates2(results[0],nb1,nb2,&nb[0]);
        results[0] = reducar(results[0]);
    } else {
        results[0][0] = 48 ;
        results[0][1] = '\0' ;
    }
    results[1][0] = pass;
    return(results);
}