/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:03 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:06 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	int				i;

	arr1 = (unsigned char *) s1;
	arr2 = (unsigned char *) s2;
	i = 0;
	while (n > 0)
	{
		if (arr1[i] != arr2[i])
			return (arr1[i] - arr2[i]);
		n--;
		i++;
	}
	return (0);
}
