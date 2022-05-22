/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:30 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:28 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*arr1;
	unsigned char	*arr2;
	size_t			i;

	arr1 = (unsigned char *) str1;
	arr2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (arr1[i] != arr2[i] || arr1[i] == '\0' || arr2[i] == '\0')
			return (arr1[i] - arr2[i]);
		i++;
	}
	return (0);
}
