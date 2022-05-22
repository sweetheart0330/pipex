/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:52 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/05 19:31:12 by Bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*arr;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) < len)
		arr = malloc(sizeof(*arr) * (ft_strlen(s) + 1));
	else
		arr = malloc(sizeof(*arr) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			arr[j++] = s[i];
		i++;
	}
	arr[j] = 0;
	return (arr);
}
