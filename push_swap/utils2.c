/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:01:40 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/23 11:24:57 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	char	*c;

	c = (char *)s;
	while (n > 0)
		c[--n] = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (ret)
		ft_bzero(ret, size * count);
	return (ret);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!s1)
		return (1);
	while (i < n)
	{
		if (!c2[i] && !c1[i])
			return (0);
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

int	get_index(t_stack stack, int list)
{
	int		i;
	t_node	*tmp;
	t_node	*start;

	tmp = stack.top;
	if (tmp == NULL)
		return (-1);
	start = tmp;
	i = 0;
	while (1)
	{
		if (tmp->data == list)
			return (i);
		i++;
		tmp = tmp->next;
		if (tmp == start)
			break ;
	}
	return (-1);
}
