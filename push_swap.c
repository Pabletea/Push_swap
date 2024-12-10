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

int *validate_input(int argc, char *argv[], int *stackValues);
void imprimir_pila(t_stack *stack);

int main(int argc, char *argv[])
{
    int *stackValues;
    t_stack stack;
    t_stack stack_b;

    stackValues = (int *)malloc((argc - 1) * sizeof(int));
    if (!stackValues)
        return (0);
    

    stackValues = validate_input(argc,argv,stackValues);
    if(fillStack(&stack,stackValues,argc - 1) != 1)
    {
        free(stackValues);
        return (0);
    }
    
    initializeStack(&stack_b,argc - 1);



    if (stackValues) {

        printf("----------------\n");
        printf("STACK A (inicial):\n");
        imprimir_pila(&stack);

        printf("----------------\n");
        printf("STACK B (inicial):\n");
        imprimir_pila(&stack_b);
        printf("*********************************");
    } else {
        printf("Error\n");
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

int *validate_input(int argc, char *argv[], int *stackValues)
{
    int i; 
    int j;
    int z;
    int string_check;
    int *seen_numbers;
    int seen_count = 0;
    int number;

    if (argc <= 1)
        return (NULL);

    // Reservar memoria para almacenar poder almacenar los numeros y comprobar que no hay duplicados
    seen_numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (!seen_numbers)
        return (NULL);
    stackValues = (int *)malloc((argc - 1) * sizeof(int));
    if (!stackValues)
    {
        free(seen_numbers);
        return (NULL);
    }
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
            free(stackValues);
            free(seen_numbers); // Liberar memoria antes de salir
            return (NULL);
        }

        // Convertir el argumento a entero
        number = ft_atoi(argv[i]);
        printf("Numero convertido %d", number);

        if (number > 2147483647 || number < -2147483647)
        {
            free(stackValues);
            free(seen_numbers);
            return (NULL);
        }
        // Verificar si el número ya fue visto
        z = 0;
        while (z < seen_count)
        {
            if (seen_numbers[z] == number)
            {
                free(stackValues);
                free(seen_numbers);
                return (NULL);
            }
            z++;
        }
        // Agregar número al array de números vistos
        seen_numbers[seen_count] = number;
        seen_count++;
        i++;
    }
    
    ft_memcpy(stackValues,seen_numbers,(argc-1)*sizeof(int));
    free(seen_numbers);
    return (stackValues);
}


