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

void negative(int neg,struct number_s *list) 
{
    neg = neg % 2;
    if (neg != 0) {
        list->neg = 1;
    }else{
        list->neg = 0;
    }
}

int estunsignedifpar(char str ,char **outil)
{
    int a = 2;
    int pass = 0;

    while(a < 7 && pass != 1) {
        if(outil[1][a] == str) {
            pass = 1;
        }
        a++;
    }
    return(pass);
}
char **comptnumber(char **str, char **outil,char end)
{
    int pass = 0;
    int pass2 = 1;
    int i = 0;

    while (str[0][i] != end && pass != 1) {
        if (estunsignedifpar(str[0][i],outil) == 1 && (i != 0 && estunsignedifpar(str[0][i-1],outil) == 0)) {
            pass = 1;
            if (str[0][i] == outil[1][1]) {
                pass2 = 0;
               
            }
        }
        i++;
    }
    *str = *str + i;
    if (pass2 == 0) {
        *str = *str - 1;
    }
    return(str);
}

char **number(char **str, char **outil,struct number_s *list,char end) 
{
    int i = 0;
    int pass = 0;
    int a = 0;
    int neg = 0;
    int pass2 = 0;
    int b = 0;
    int save;
    char *number;

    while (str[0][i] != '\0' && pass != 3) { 
        if (pass == 0) {
            pass2 = 0;
            a = 0;
            if (str[0][i] == outil[1][3]) {
                neg++;
            }else{
                while (a < my_strlen(outil[0]) && pass2 == 0) {
                    if(str[0][i] == outil[0][a]) {
                        negative(neg,list);
                        pass = 1;
                        pass2 = 1;
                    }
                    a++;
                }
            }
        }
        if (pass == 1) {
            save = i;
            neg = 1;
            while (estunsignedifpar(str[0][i],outil) == 0 && str[0][i] != end){
                i++;
                neg++;
            }
            i = save;
            number = malloc(sizeof(char) * neg);
            number[neg - 1] = '\0';
            pass = 2;
        }
        if (pass == 2) {
            pass2 = 0;
            a = 0;
            while (a < my_strlen(outil[0]) && pass2 == 0) {
                if(str[0][i] == outil[0][a]) {
                    number[b] = str[0][i];
                    pass2 = 1;
                    b++;     
                }
                a++;
            }
            if (pass2 == 0)
                pass = 3;
        }
        i++;
    }
    list->nb = number;
    *str = *str + i;
    return(str);
}

int base10(struct number_s *list , char *outil)
{
    int i = 0;
    int a = 0;

    while (i < my_strlen(list->nb)) {
        a = 0;
        while (a < 10) {
            if (outil[a] == list->nb[i]) {
                list->nb[i] = a + 48;
            }
            a++; 
        }
        i++;
    }
    return(1);
}

/*
int strlol(char *str, char **endptr,char **outil) 
{
    int i = 1;

    while(((str[i] == outil[1][3] && !(str[i-1] > 47 && str[i-1] < 58) && str[i+1] > 47 && str[i+1] < 58) || (str[i] > 47 && str[i] < 58)) && str[i] != '\0') {
        i++;
    }
    *endptr = &str[i];
    return(0);
}
*/

char **calcul(struct number_s *list) 
{
    struct number_s *backup = list;
    struct number_s *next;
    int pass = 0;
    char test;
    char *nb1;
    char *nb2;
    char **result;

    result = malloc(sizeof(char *) * 2);
    while(list != NULL) {
        pass = 1;
        if (list->prio == 3) {
            if (list-> op == '*') {
                nb1 = list->nb;
                next = list->next;
                nb2 = next->nb;
                result = multimain(nb1,nb2,list->neg,next->neg);
                list->nb = result[0];
                list->neg = result[1][0];
                list->op = next->op;
                list->prio = next->prio;
                list->next = next->next;
                if (next->prio == 3) {
                    pass = 0;
                }
            }else if (list-> op == '%'){
                nb1 = list->nb;
                next = list->next;
                nb2 = next->nb;
                if (my_strlen(nb2) == 1 && nb2[0] == '0') {
                    my_putstr(ERROR_MSG);
                    exit(84);
                }
                result = modulomain(nb1,nb2,list->neg);
                list->nb = result[0];
                list->neg = result[1][0];
                list->op = next->op;
                list->prio = next->prio;
                list->next = next->next;
                if (next->prio == 3) {
                    pass = 0;
                }
            }else{
                nb1 = list->nb;
                next = list->next;
                nb2 = next->nb;
                if (my_strlen(nb2) == 1 && nb2[0] == '0') {
                    my_putstr(ERROR_MSG);
                    exit(84);
                }
                result = divimain(nb1,nb2,list->neg,next->neg);
                list->nb = result[0];
                list->neg = result[1][0];
                list->op = next->op;
                list->prio = next->prio;
                list->next = next->next;
                if (next->prio == 3) {
                    pass = 0;
                }
            }
        }
        if (pass == 1) {
            list = list->next;
        }
    }
    list = backup;
    while(list->next != NULL) {
        if (list-> op == '+') {
            nb1 = list->nb;
            next = list->next;
            nb2 = next->nb;
            result = addmain(nb1,nb2,list->neg,next->neg);
            list->nb = result[0];
            list->neg = result[1][0];
            list->op = next->op;
            list->op = next->op;
            list->prio = next->prio;
            list->next = next->next;
        }else if (list-> op == '-') {
            nb1 = list->nb;
            next = list->next;
            nb2 = next->nb;
            result = minusmain(nb1,nb2,list->neg,next->neg);
            list->nb = result[0];
            list->neg = result[1][0];
            list->op = next->op;
            list->prio = next->prio;
            list->next = next->next;
        }
    }
    result = malloc(sizeof(char *) *2);
    result[0] = list->nb;
    test = list->neg;
    result[1] = &test;
    return(result);
}

char *chdebase(struct number_s *list,char **outil)
{
    int sizebase = my_strlen(outil[0]);
    char *nb;
    char *resu;
    int nblist = 0;
    char *nb1;
    char *base;
    char **result;
    int i = 0;
    int a = 0;

    nb = malloc(sizeof(char) * (sizebase + 1));
    while (i < sizebase) {
        nb[i] = 48;
        i++;
    }
    nb[sizebase] = '\0';
    i = 0;
    while (outil[0][a] != '\0') {    
        if (outil[0][a] == list->nb[i]) {
            nblist = a;
        }
        a++;
    }
    base = inttochar(sizebase);
    nb1 = inttochar(nblist);
    result = addmain(nb1,nb,0,0);
    free(nb1);
    nb = result[0];
    i++;
    while (list->nb[i] != '\0') {
        a = 0;
        result = multimain(nb,base,0,0);
        nb = result[0];
        while (outil[0][a] != '\0') {    
            if (outil[0][a] == list->nb[i]) {
                nblist = a;
            }
            a++;
        }
        nb1 = inttochar(nblist);
        result = addmain(nb1,nb,0,0);
        free(nb1);
        nb = result[0];
        i++;
    }
    resu = reducar(nb);
    free(nb);
    return(resu);
}

char **separate(char **str,char end,char **outil) 
{
    struct number_s *list = NULL;
    struct number_s *element;
    struct number_s *backups;
    int i = 0;
    char *temp;
    char **results;
    int nbpare = 0;
    char *backup = *str;

    while(**str != end) {
        if (**str == outil[1][0]) {
            *str = *str + 1;
            i++;
            nbpare++;
            while (nbpare != 0) {
                while (**str != outil[1][1] && **str != '\0') {
                    if (**str == outil[1][0]) {
                        nbpare++;
                    }
                    *str = *str + 1;
                }
                if (**str != '\0') { 
                    *str = *str + 1;
                }
                nbpare--;
                if (str[0][1] == outil[1][0]) {
                   i++;
                   nbpare++;
                   *str = *str + 1;
                }
            }
        }
        if (**str != end) {
            str = comptnumber(str,outil,end);
            i++;
        }
    }
    *str = backup;
    while (i != 0) {
        element = malloc(sizeof(*element));
        element->next = list;
        list = element;
        i--;
    }
    backups = list;
    while (list != NULL) {
        if (**str == outil[1][0]) {
            *str = *str + 1;
            results = separate(str,outil[1][1],outil);
            list->neg = results[1][0];
            *str = *str + 1;
            list->nb = results[0];
        }else{
            str = number(str,outil,list,end);
            if (my_strlen(outil[0]) == 10) {
                base10(list,outil[0]);
            }else{
                temp = chdebase(list,outil);
                free(list->nb);
                list->nb = temp;
            }
        }
        *str = *str-1;
        if (**str == outil[1][4] || **str == outil[1][5] || **str == outil[1][6]) {
            list->prio = 3;
            if (**str == outil[1][4]) {
                list->op = '*';
            }else if(**str == outil[1][5]) {
                list->op = '/';
            }else{
                list->op = '%';
            }
        }else if (**str == outil[1][2] || **str == outil[1][3]) {
            list->prio = 1;
            if (**str == outil[1][2]) {
                list->op = '+';
            }else{
                list->op = '-';
            }
        }else{
            list->prio = 0;
        }
        list = list->next;
        *str = *str + 1;
    }
    results = calcul(backups);
    list = backups;
    while(list->next != NULL) {
        element = list->next;
        free(list);
        list = element;
    }
    return(results);
}

int eval_expr (char * str ,char *base , char *signe) 
{
    char **nb;
    char **outil;

    outil = malloc(sizeof(char *) * 2);
    outil[0] = base;
    outil[1] = signe;
    nb = separate(&str,'\0',outil);
    reverse(nb, nb[1][0],outil);
    return(1);
}


