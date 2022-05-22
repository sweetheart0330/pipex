/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:56:21 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/11 16:56:22 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*tmp;

	if (list)
	{
		if (*list)
		{
			tmp = ft_lstlast(*list);
			tmp->next = new;
		}
		else
			*list = new;
	}
}
