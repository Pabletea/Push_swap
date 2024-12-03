/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:59 by pabalons          #+#    #+#             */
/*   Updated: 2024/12/03 12:37:39 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int validate_input(int argc,char *argv[]);
void imprimir_pila(t_stack *stack);

int main(int argc, char *argv[])
{
    int check;
    t_stack stack;
    t_stack stack_b;

    t_node *node_a_1 = (t_node*)malloc(sizeof(t_node));
    node_a_1->data = 50;
    node_a_1->next = NULL;
    t_node *node_b_1 = (t_node*)malloc(sizeof(t_node));
    node_b_1->data = 1;
    node_b_1->next = NULL;

    t_node *node_a_2 = (t_node*)malloc(sizeof(t_node));
    node_a_2->data = 20;
    node_a_2->next = node_a_1;
    t_node *node_b_2 = (t_node*)malloc(sizeof(t_node));
    node_b_2->data = 2;
    node_b_2->next = node_b_1;


    t_node *node_a_3 = (t_node*)malloc(sizeof(t_node));
    node_a_3->data = 10;
    node_a_3->next = node_a_2;
    t_node *node_b_3 = (t_node*)malloc(sizeof(t_node));
    node_b_3->data = 3;
    node_b_3->next = node_b_2;

    stack.top = node_a_3;
    stack_b.top = node_b_3;

    check = validate_input(argc,argv);
    if (check == 1)
    {
        ft_printf("----------------\n");
        ft_printf("STACK A\n");
        imprimir_pila(&stack);
        ft_printf("----------------\n");
        ft_printf("STACK B\n");
        imprimir_pila(&stack_b);
        
        ss(stack,stack_b);
        ft_printf("************************************************\n");
        ft_printf("----------------\n");
        ft_printf("STACK A\n");
        imprimir_pila(&stack);
        ft_printf("----------------\n");
        ft_printf("STACK B\n");
        imprimir_pila(&stack_b);

    }
    else{
        ft_printf("Error\n");
    }
    
    return(0);

}

void imprimir_pila(t_stack *stack) {
    t_node *actual = stack->top;

    while (actual != NULL) {
        ft_printf("%d ", actual->data);
        actual = actual->next;
    }
    ft_printf("\n");
}
//Manejar los argumentos recibidos por parametro

int validate_input(int argc, char *argv[])
{
    int i; 
    int j;
    int z;
    int string_check;
    int *seen_numbers;
    int seen_count = 0;
    int number;

    // Reservar memoria para almacenar poder almacenar los numeros y comprobar que no hay duplicados
    seen_numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (!seen_numbers)
        return (0);

    i = 1;
    while (i < argc)
    {
        j = 0;
        string_check = 1;

        // Validar cada argumento como un número
        while (argv[i][j])
        {
            if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0 )
            {
                j++;
                if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                {
                    string_check = 0;
                    break;
                }
            }
            else if (argv[i][j] >= '0' && argv[i][j] <= '9')
                j++;
            else
            {
                string_check = 0;
                break;
            }
        }

        if (string_check == 0) // Argumento inválido
        {
            free(seen_numbers); // Liberar memoria antes de salir
            return (0);
        }

        // Convertir el argumento a entero
        number = ft_atoi(argv[i]);

        if (number > 2147483647 || number < -2147483647)
            return (0);
        
        // Verificar si el número ya fue visto
        z = 0;
        while (z < seen_count)
        {
            if (seen_numbers[z] == number)
            {
            free(seen_numbers);
            return (0);
            }
            z++;
        }
        // Agregar número al array de números vistos
        seen_numbers[seen_count] = number;
        seen_count++;
        i++;
    }
    free(seen_numbers);
    return (1);
}


