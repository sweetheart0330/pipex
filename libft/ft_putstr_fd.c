/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:28:39 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:31:15 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	if (!c)
		return ;
	i = 0;
	while (c[i] != '\0')
	{
		write(fd, &c[i], 1);
		i++;
	}
}
