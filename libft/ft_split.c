/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpirzad <bpirzad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:14:11 by bpirzad           #+#    #+#             */
/*   Updated: 2021/11/03 16:34:17 by Bpirzad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size_of_str(const char *sent, char del)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	if (!sent[i])
		return (0);
	while (sent[i])
	{
		if ((sent[i + 1] == del || !sent[i + 1]) && sent[i] != del)
			size++;
		i++;
	}
	return (size);
}

static const char	*scroll_del(const char *str, char del)
{
	if (!str)
		return (NULL);
	while (*str && *str == del)
	{
		str++;
	}
	if (!str)
		return (NULL);
	return (str);
}

static char	*get_str(const char *s, char del)
{
	int			begin;
	int			end;
	char		*next_str;
	const char	*str;

	begin = 0;
	end = 0;
	str = scroll_del(s, del);
	if (!str)
		return (NULL);
	while (str[end] && str[end] != del)
		end++;
	next_str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!next_str)
		return (NULL);
	while (begin < end)
	{
		next_str[begin] = str[begin];
		begin++;
	}
	next_str[begin] = '\0';
	return (next_str);
}

static const char	*scroll_next_str(const char *str, char del)
{
	const char	*without_del;

	without_del = scroll_del(str, del);
	if (!without_del)
		return (NULL);
	while (*without_del && *without_del != del)
	{
		without_del++;
	}
	if (!without_del)
		return (NULL);
	return (without_del);
}

char	**ft_split(char const *s, char c)
{
	const char	*last_stop;
	char		**str;
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (get_size_of_str(s, c) + 1));
	last_stop = s;
	if (!str)
		return (NULL);
	while (i < get_size_of_str(s, c))
	{
		str[i] = get_str(last_stop, c);
		if (!str[i++])
		{
			while (i--)
				free(str[i]);
			free(str);
			return (NULL);
		}
		last_stop = scroll_next_str(last_stop, c);
	}
	str[i] = NULL;
	return (str);
}
