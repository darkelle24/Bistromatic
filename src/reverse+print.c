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

void reverse(char **nb,int neg,char **outil)
{
    int sizelist = my_strlen(nb[0]);
    char *base = inttochar(my_strlen(outil[0]));
    int sizebase = my_strlen(base);
    char **result;
    char **nombreprint;
    char *result2;
    int lenresult = sizelist;
    int i1 = 0;
    int i = 0;
    int a = 0;
    int pass = 0;

    if (neg == 1) {
        write(1, "-" ,1);
    }
    result = malloc(sizeof(char *)*2);
    nombreprint = malloc(sizeof(char *)*2);
    result2 = malloc(sizeof(char) * (my_strlen(outil[0]) * sizelist));
    if (my_strlen(outil[0]) == 10) {
        while (i < sizelist) {
            a = 0;
            while (outil[0][a] != '\0') {
                if (a == nb[0][i] - 48) {
                    result2[i] = outil[0][a];
                }
                a++;
            }
            i++;
        }
        result2[i] = '\0';
        my_putstr(result2); 
    }else{
        while(pass != -1) {
            if (lenresult < sizebase) {
                pass = -1;
            }else if(lenresult == sizebase) {
                i1 = 0;
                pass = 0;
                while (pass == 0 && base[i1] != '\0') {
                    if (nb[0][i1] > base[i1]) {
                        pass = 1;
                    }else if (nb[0][i1] < base[i1]) {
                        pass = -1;
                    }
                    i1++;
                }
            }
            if (pass != -1) {
                result = divimain(nb[0], base ,0 ,0);
                nombreprint = modulomain(nb[0], base ,0);
                lenresult = my_strlen(result[0]);
                nb[0] = result[0];
            } else {
                nombreprint[0] = nb[0];
            }    
            a = 0;
            while (outil[0][a] != '\0') {
                if (a == chartoint(nombreprint[0])) {
                    result2[i] = outil[0][a];
                }
                a++;
            }
            i++;
        }
        result2[i] = '\0';
        my_putstrreverse(result2);
    }
}
