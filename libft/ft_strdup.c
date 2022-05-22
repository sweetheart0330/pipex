/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:52 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:19 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *) s1;
	dst = (char *)malloc(sizeof(*dst) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	while (i < ft_strlen(s1) + 1)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
