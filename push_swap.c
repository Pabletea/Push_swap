/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:59 by pabalons          #+#    #+#             */
/*   Updated: 2024/11/25 13:22:57 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int argc,char *argv[]);

int main(int argc, char *argv[])
{
    int check;

    check = check_args(argc,argv);
    if (check == 1)
    {
        printf("OK");
    }
    else{
        printf("KO");
    }
    
    return(0);

}
//Manejar los argumentos recibidos por parametro

int check_args(int argc, char *argv[])
{
    int i; 
    int j;
    int z;
    int string_check;
    int *seen_numbers;
    int seen_count = 0;
    int number;


    seen_numbers = (int *)malloc((argc - 1) * sizeof(int));
    if (!seen_numbers)
        return (0);

    i = 1;
    while (i < argc)
    {
        j = 0;
        string_check = 1; // Inicializar como válido

        // Validar cada argumento como un número
        while (argv[i][j])
        {
            if (argv[i][j] == '-' && j == 0)
            {
                j++;
                if (!(argv[i][j] >= '0' && argv[i][j] <= '9')) // '-' debe ir seguido de un dígito
                {
                    string_check = 0;
                    break;
                }
            }
            else if (argv[i][j] >= '0' && argv[i][j] <= '9') // Validar si es un dígito
                j++;
            else
            {
                string_check = 0; // No es válido
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

        // Verificar si el número ya fue visto
        z = 0;
        while (j < seen_count)
        {
            if (seen_numbers[z] == number) // Número repetido
            {
            free(seen_numbers); // Liberar memoria antes de salir
            return (0);
            }
            j++;
        }
        seen_numbers[seen_count] = number;
        seen_count++;

        i++;
    }

    // Liberar memoria y devolver éxito
    free(seen_numbers);
    return (1); // Todos los argumentos son válidos y únicos
}
