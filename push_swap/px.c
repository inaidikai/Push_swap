/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:20:18 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:44:59 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list *list, int flag)
{
	if (list->b.top)
	{
		push(&list->a, reup(&list->b));
		if (flag)
		{
			write(1, "pa\n", 3);
		}
	}
	else
		write(1, "error", 6);
}

void	pb(t_list *list, int flag)
{
	if (list->a.top)
	{
		push(&list->b, reup(&list->a));
		if (flag)
			write(1, "pb\n", 3);
	}
	else
		write(1, "error", 6);
}
