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
// void imprimir_pila(t_stack *stack, const char *nombre);
void imprimir_estado(t_stack *a, t_stack *b);

int main(int argc, char *argv[])
{
    int *stackValues;
    t_stack stack;
    t_stack stack_b;
    int stack_nodes;

    stackValues = (int *)malloc((argc - 1) * sizeof(int));
    if (!stackValues)
        return (0);
    

    stackValues = validate_input(argc,argv,stackValues);

    
    initializeStack(&stack,argc - 1);
    initializeStack(&stack_b,argc - 1);

    if(fillStack(&stack,stackValues,argc - 1) != 1)
    {
        free(stackValues);
        return (0);
    }



    stack_nodes = stack_len(&stack);

    if (stackValues) {

        // stack_nodes = stack_len(stack);
        // Imprimir el estado inicial
        imprimir_estado(&stack, &stack_b);
        
        if (stack_nodes == 3)
        {
            printf("Exec sortThree:\n\n");
            sort_three(&stack);
            imprimir_estado(&stack, &stack_b);
        }
        printf("Exec pa:\n\n");
        pa(&stack,&stack_b);
        imprimir_estado(&stack,&stack_b);

        printf("Exec pb:\n\n");
        pb(&stack,&stack_b);
        imprimir_estado(&stack,&stack_b);

        printf("Exec ra:\n\n");
        ra(&stack);
        imprimir_estado(&stack,&stack_b);

        printf("Exec rb:\n\n");
        rb(&stack_b);
        imprimir_estado(&stack,&stack_b);

        printf("Exec rra:\n\n");
        rra(&stack);
        imprimir_estado(&stack,&stack_b);

        printf("Exec rrb:\n\n");
        rrb(&stack_b);
        imprimir_estado(&stack,&stack_b);






    } else {
        printf("Error\n");
    }
    
    return(0);

}


void imprimir_estado(t_stack *a, t_stack *b) {
    t_node *current_a = a->top;
    t_node *current_b = b->top;
    int max_height = 0;

    // Determinar la altura máxima entre ambas pilas
    t_node *temp_a = current_a;
    t_node *temp_b = current_b;
    while (temp_a != NULL) {
        max_height++;
        temp_a = temp_a->next;
    }
    while (temp_b != NULL) {
        max_height++;
        temp_b = temp_b->next;
    }

    // Imprimir las pilas en columnas
    for (int i = 0; i < max_height; i++) {
        if (current_a != NULL) {
            printf("| %d ", current_a->data);
            current_a = current_a->next;
        } else {
            printf("|    "); // Espacio vacío para pila a
        }

        if (current_b != NULL) {
            printf("| %d ", current_b->data);
            current_b = current_b->next;
        } else {
            printf("|   "); // Espacio vacío para pila b
        }

        printf("|\n");
    }

    // Imprimir el nombre de cada pila debajo
    printf("|----|---|\n");
    printf("  a    b \n");
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
    long number;

    if (argc <= 1)
        return (NULL);

    // Reservar memoria inicializada para evitar valores basura
    seen_numbers = (int *)calloc((argc - 1), sizeof(int));
    if (!seen_numbers)
        return (NULL);

    i = 1;
    while (i < argc)
    {
        j = 0;
        string_check = 1;

        // Validar que el argumento sea un número
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
            free(seen_numbers);
            return (NULL);
        }

        // Convertir el argumento a entero
        number = ft_atoi(argv[i]);

        if (number > 2147483647 || number < -2147483647)
        {
            free(seen_numbers);
            return (NULL);
        }

        // Verificar si el número ya fue visto
        z = 0;
        while (z < seen_count)
        {
            if (seen_numbers[z] == number)
            {
                free(seen_numbers);
                return (NULL);
            }
            z++;
        }

        // Agregar número al array de números vistos y stackValues
        seen_numbers[seen_count] = (int)number;
        stackValues[i - 1] = (int)number;
        seen_count++;
        i++;
    }

    free(seen_numbers); // Liberar memoria de números vistos
    return (stackValues);
}



