/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:49:30 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/19 15:37:25 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fry(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		free(c[i++]);
	}
	free(c);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] >= 9) && \
		(str[i + 1] == '+' || str[i + 1] == '-'))
			return (0);
		if ((str[i] == '+' || str[i] == '-'))
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	spacchk(char *argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			j++;
		i++;
	}
	if (i == j)
		return (0);
	return (1);
}

int	store(int argc, char **argv, t_stack *a)
{
	char	**c;
	int		i;

	c = NULL;
	if (argc < 2)
		return (0);
	i = argc;
	while (--i > 0)
	{
		if (spacchk(argv[i]))
			c = ft_split(argv[i], ' ');
		else
		{
			if (c)
				fry(c);
			return (write(2, "Error\n", 6), 0);
		}
		if (!*c)
			return (0);
		if (!check(c, a))
			return (fry(c), 0);
		fry(c);
	}
	return (1);
}
