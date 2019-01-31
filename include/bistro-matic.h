/*
** EPITECH PROJECT, 2018
** bistro-matic.h
** File description:
** prototyp the functions in bistro-matic
*/
#ifndef BISTRO_MATIC_H_
# define BISTRO_MATIC_H_

#define OP_OPEN_PARENT_IDX  0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX         2
#define OP_SUB_IDX          3
#define OP_NEG_IDX          3
#define OP_MULT_IDX         4
#define OP_DIV_IDX          5
#define OP_MOD_IDX          6

#define EXIT_USAGE    84
#define EXIT_BASE     84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC   84
#define EXIT_READ     84
#define EXIT_OPS      84

#define SYNTAX_ERROR_MSG "syntax error"
#define ERROR_MSG        "error"

struct number_s {
    char *nb;
    int neg;
    char op;
    int prio;
    struct number_s *next;
};

int my_strlen(char const *str);
char **multimain(char *nb1, char *nb2 ,int neg1 ,int neg2);
char **addmain(char *nb1, char *nb2 ,int neg1 ,int neg2);
int eval_expr (char * str ,char *base , char *signe);
char *chdebase(struct number_s *list,char **outil);
char *inttochar(int nblist);
char **calcul(struct number_s *list);
char **number(char **str, char **outil,struct number_s *list,char end);
char **comptnumber(char **str, char **outil,char end);
int estunsignedifpar(char str ,char **outil);
void negative(int neg,struct number_s *list);
char **arraycreate(int nbtotal, int plus , int neg,char **result);
char *separates(char *finalnb,char *nb1,char *nb2,int *nb);
char *add(char *finalnb,char *nb1,char *nb2,int *nb);
char *minus(char *finalnb,char *nb1,char *nb2,int *nb);
char *multi(int number1 , int number2 ,char *finalnb,char *av1,char *av2);
char **separate(char **str,char end,char **outil);
char *reducar(char *nb);
char **modulomain(char *nb1, char *nb2 ,int neg2);
char **divimain(char *nb1, char *nb2 ,int neg1 ,int neg2);
char **minusmain(char *nb1, char *nb2 ,int neg1 ,int neg2);
void reverse(char **nb,int neg,char **outil);
char *separates2(char *finalnb,char *nb1,char *nb2,int *nb);
int chartoint(char *nb);
char *divi(int number1 , int number2 ,char *av1,char *av2);
char *modul(int number1 , int number2 ,char *av1,char *av2);
int my_putstrreverse(char const *str);
int my_putstr(char const *str);

#endif /* !BISTRO_MATIC_H_ */