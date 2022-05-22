/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:27:28 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:30:20 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int chr)
{
	if ((chr >= 65 && chr <= 90) || (chr >= 97 && chr <= 122))
		return (1);
	return (0);
}