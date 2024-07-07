/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:57 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:46:04 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list *rra, int flag)
{
	rra->a.top = rra->a.top->prev;
	pos(&rra->a);
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_list *rrb, int flag)
{
	rrb->b.top = rrb->b.top->prev;
	pos(&rrb->b);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_list *rrb, int flag)
{
	rrb->a.top = rrb->a.top->prev;
	pos(&rrb->a);
	rrb->b.top = rrb->b.top->prev;
	pos(&rrb->b);
	if (flag)
		write(1, "rrr\n", 4);
}
