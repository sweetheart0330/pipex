/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:56:08 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/11 16:56:10 by bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}