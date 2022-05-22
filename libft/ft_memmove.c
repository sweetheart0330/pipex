/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:13 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:09 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*to;
	char	*from;

	to = (char *) dst;
	from = (char *) src;
	if ((char *) dst == (char *) src)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (to < from)
		ft_memcpy (dst, src, len);
	else if (to > from)
	{
		while (len-- > 0)
			to[len] = from[len];
	}
	return (dst);
}
