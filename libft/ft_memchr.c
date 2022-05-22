/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:27:59 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/05 19:55:27 by Bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*arr1;
	size_t			i;

	arr1 = (unsigned char *)arr;
	i = 0;
	while (i < n)
	{
		if (arr1[i] == (unsigned char)c)
			return (&arr1[i]);
		i++;
	}
	return (NULL);
}
