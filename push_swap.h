#ifndef PUSH_SWAP
# define PUSH_SWAP
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "ft_libft/libft.h"

//Definimos cada nodo dentro de un stack
typedef struct Node {
    int data;
    struct Node *next;
} Node;

//Definimos el stack
typedef struct Stack
{
    Node *top;
} Stack;



# endif