/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:27:54 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/06 13:17:26 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static long	ft_nbrlen(long nbr)
{
	long	i;

	i = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*newstr(size_t len)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_bzero(str, len + 1);
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	cpy;

	len = ft_nbrlen(n);
	cpy = n;
	if (n < 0)
	{
		cpy = -n;
		len++;
	}
	str = newstr(len);
	if (!str)
		return (NULL);
	str[--len] = cpy % 10 + '0';
	while (cpy > 9)
	{
		cpy /= 10;
		str[--len] = cpy % 10 + '0';
	}
	if (n < 0)
		*(str + 0) = '-';
	return (str);
}
