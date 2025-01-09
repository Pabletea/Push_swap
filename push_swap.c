/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabalons <pabalons@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 11:54:59 by pabalons          #+#    #+#             */
/*   Updated: 2025/01/09 15:48:28 by pabalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *validate_input(int argc, char *argv[], int *stackValues);
// void imprimir_pila(t_stack *stack, const char *nombre);
void imprimir_estado(t_stack **a, t_stack **b);
void getValues(int ar, char *av[]);
char	*arguments_union(char **argv);
static void	free_all_memory(char *argv_union, char **arr_arguments);
static int	check_arguments(char **argv);
void convert_strings_to_integers(const char *strArray[], int intArray[], int size);

int main(int argc, char *argv[])
{

    t_stack **stack_a;
    t_stack **stack_b;
    char *megaArgv;
    char **valoresArgumentos;


    megaArgv = NULL;
    valoresArgumentos = NULL;


    if (argc < 2)
        return (-1);

    megaArgv = arguments_union(argv);
    valoresArgumentos = ft_split(megaArgv,' ');

    *stack_a = NULL;
    *stack_b = NULL;

    if (!check_arguments(valoresArgumentos))
        return(free_all_memory(megaArgv,valoresArgumentos),0);
    
    int size = sizeof(valoresArgumentos) / sizeof(valoresArgumentos[0]);
    int stackValues[size];
    
    convert_strings_to_integers(valoresArgumentos,stackValues,size);
    

    ft_printf(1,"Cadena coon todos los argumentos = %s",megaArgv);

    stack_a = (t_stack **)malloc(sizeof(t_stack));
    stack_b = (t_stack **)malloc(sizeof(t_stack));



    initializeStack(stack_a,stackValues, (argc-1));
    free(stackValues);

    if (stackValues) {

        ft_printf(1,"ESTADO INICIAL :\n");
        imprimir_estado(stack_a,stack_b);
        // if(isSorted(stack_a))
        // {
        //     free_stack(*stack_a);
        //     free_stack(*stack_b);
        //     free(stack_a);
        //     free(stack_b);
        //     return (0);
        // }else{
        //     sortStack(stack_a,stack_b);
        // }
    } else {
        ft_printf(2,"Error\n");
    }

    ft_printf(1,"ESTADO FINAL :\n");
    imprimir_estado(stack_a,stack_b);

    free_stack(*stack_a);
    free_stack(*stack_b);
    free(stack_a);
    free(stack_b);

    return(0);
}


void imprimir_estado(t_stack **a, t_stack **b) {
    t_stack *current_a = *a;
    t_stack *current_b = *b;
    int max_height = 0;

    // Determinar la altura máxima entre ambas pilas
    t_stack *temp_a = *a;
    t_stack *temp_b = current_b;
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
    if (argc <= 2)
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

static int	check_arguments(char **argv)
{
	int		i;

	i = 0;
	if (!argv[i])
		return (ft_printf(2, "Error: No arguments provided\n"), 0);
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
		{
			ft_printf(2, "Error: incorrect arguments\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static void	free_all_memory(char *argv_union, char **arr_arguments)
{
	char	**temp;

	temp = arr_arguments;
	if (argv_union != NULL)
		free(argv_union);
	if (arr_arguments != NULL)
	{
		while (*temp)
		{
			free(*temp);
			temp++;
		}
	}
	free (arr_arguments);
}


char	*arguments_union(char **argv)
{
	int		i;
	char	*union_str;
	char	*temp_str;

	i = 1;
	union_str = ft_calloc(1, 1);
	if (!union_str)
		return (NULL);
	union_str[0] = '\0';
	while (argv[i])
	{
		temp_str = ft_strjoin(union_str, " ");
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		temp_str = ft_strjoin(union_str, argv[i]);
		if (!temp_str)
			return (free(union_str), NULL);
		free(union_str);
		union_str = temp_str;
		i++;
	}
	return (union_str);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || strlen(str) == 0)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (is_valid_integer_value(str));
}


int	is_valid_integer_value(char *str)
{
	long	num;
	long	check_num;

	num = ft_atoi(str);
	check_num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	else if (num != check_num)
		return (0);
	return (1);
}
long	ft_atol(const char *nptr)
{
	int			i;
	int			s;
	long		n;

	i = 0;
	n = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	return (n * s);
}
size_t ft_sizeof(int *array) {
    size_t size = 0;
    while (array[size] != '\0') {
        size++;
    }
    return size * sizeof(int); // Multiplica por el tamaño de cada elemento (int)
}

void convert_strings_to_integers(const char *strArray[], int intArray[], int size) {
    int i = 0;
    while (i < size) {
        intArray[i] = atoi(strArray[i]);
        i++;
    }
}
