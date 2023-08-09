/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scespede <scespede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:52:47 by scespede          #+#    #+#             */
/*   Updated: 2023/05/24 12:53:32 by scespede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
	{
		return (NULL);
	}
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
//int main() {
//    int* ptr = NULL;
//    int i, n;
//
//    n = 5; // Tamaño del array (ejemplo: 5 elementos)
//
//    // Asignar memoria utilizando calloc
//    ptr = ft_calloc(n, sizeof(int));
//
//    if (ptr == NULL) {
//        printf("Error al asignar memoria.\n");
//        return 1; // Terminar el programa con un código de error
//    }
//
//    printf("Ingrese los elementos del array:\n");
//    for (i = 0; i < n; i++) {
//        ptr[i] = i + 1; // Asignar valores al array (ejemplo: 1, 2, 3, 4, 5)
//    }
//
//    printf("Elementos del array:\n");
//    for (i = 0; i < n; i++) {
//        printf("%d ", ptr[i]); // Mostrar los valores del array
//    }
//    printf("\n");
//
//    // Liberar la memoria asignada por calloc
//    free(ptr);
//
//    return 0;
//}
