/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:00 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:21 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	arr = malloc(sizeof(*arr) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	ft_memcpy (arr, s1, ft_strlen(s1));
	ft_memcpy (arr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (arr);
}
