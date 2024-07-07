/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:49:43 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/19 15:38:06 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
	{
		return (1);
	}
	else
		return (0);
}

long	ft_atoi(const char *str)
{
	char	*p;
	long	num;
	int		sign;

	p = (char *)str;
	num = 0;
	sign = 1;
	while (*p == 32 || (*p >= 9 && *p <= 13))
		p++;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-')
			sign *= -1;
		p++;
	}
	while (ft_isdigit(*p))
	{
		num *= 10;
		num += (*p - '0');
		p++;
	}
	return (num * sign);
}

int	dupli(t_stack *list, int data)
{
	t_node	*tmp;
	int		found_duplicate;

	if (!list || !list->top)
		return (0);
	tmp = list->top;
	found_duplicate = 0;
	while (1)
	{
		if (tmp && tmp->data == data)
		{
			found_duplicate = 1;
		}
		if (tmp->data == 0 && tmp->next != list->top)
		{
			if (tmp->next->data != -1)
				tmp->next->data = -1;
		}
		tmp = tmp->next;
		if (tmp == list->top)
			break ;
	}
	return (found_duplicate);
}

int	check(char **c, t_stack *a)
{
	int		i;
	long	y;

	i = 0;
	while (c[i])
	{
		if (is_numeric(c[i]))
			i++;
		else
			return (write(2, "Error\n", 6), 0);
	}
	while (--i >= 0)
	{
		y = ft_atoi(c[i]);
		if (y > INT_MAX || y < INT_MIN)
			return (write(2, "Error\n", 6), 0);
		if (!dupli(a, y))
			push(a, y);
		else
		{
			return (write(2, "Error\n", 6), 0);
		}
	}
	return (1);
}
