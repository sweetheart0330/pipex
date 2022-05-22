/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:29:35 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:29 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *strB, const char *strA, size_t n)
{
	size_t	i;
	int		t;
	char	*str1;
	char	*str2;

	str1 = (char *) strB;
	str2 = (char *)strA;
	i = 0;
	t = 0;
	if (str2[0] == '\0')
		return (str1);
	while (i < n && str1[i] != '\0')
	{
		while (i < n && str1[i] == str2[t])
		{
			i++;
			t++;
			if (str2[t] == '\0')
				return (&str1[i - t]);
		}
		i = i - t;
		t = 0;
		i++;
	}
	return (NULL);
}
