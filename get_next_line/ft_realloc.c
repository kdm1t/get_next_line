/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilbur <mwilbur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:57:22 by mwilbur           #+#    #+#             */
/*   Updated: 2019/09/24 18:24:36 by mwilbur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void    *ft_realloc(void *ptr, size_t newsize)
{
    void    *newptr;
    
    if (!ptr)
    {
        printf("\nptr = NULL\n");
    }
    if (!ptr && newsize)
    {
        newptr = ft_memalloc(newsize);
        return (newptr);
    }
    if (!newsize && ptr)
    {
        free(ptr);
        return (NULL);
    }
    newptr = ft_memalloc(newsize);
    if (!newptr)
        return (NULL);
    newptr = ft_memcpy(newptr, ptr, 6);
    printf("\nnew_ptr after ft_memcpy : %s\n", (char*)newptr);
    free(ptr);
    ptr = NULL;
    return (newptr);
}

int     main(void)
{
    int i = 0;
    char *ptr = (char*)malloc(sizeof(char) * 6);
    printf("ptr before cycle : %i", malloc_usable_size(ptr));
    if (!ptr)
        printf("\nAllocation error\n");
    while (i < 6)
    {
        ptr[i] = '!';
        i++; 
    }
    printf("ptr after cycle : %i", malloc_usable_size(ptr));
    printf("source string = %s\n", ptr);
    ptr = (char*)ft_realloc(ptr, 10);
    printf("ptr after ft_realloc : %i", malloc_usable_size(ptr));
    while (i < 15)
    {
        ptr[i] = '.';
        i++; 
    }
    ptr[i] = '\0';
    printf("result of reallocate = %s\n", ptr);
    printf("last string of main : %i", malloc_usable_size(ptr));
    return (0);
}