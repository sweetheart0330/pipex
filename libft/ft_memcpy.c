/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:09 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:08 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*arr1;
	char		*arr2;
	size_t		i;

	arr1 = (char *) dest;
	arr2 = (char *) src;
	i = 0;
	if (!src && !dest)
		return (0);
	while (n > 0)
	{
		arr1[i] = arr2[i];
		i++;
		n--;
	}
	return (dest);
}
