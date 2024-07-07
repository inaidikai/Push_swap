/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:27 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:46:48 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list *ra, int flag)
{
	ra->a.top = ra->a.top->next;
	pos(&ra->a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_list *rb, int flag)
{
	rb->b.top = rb->b.top->next;
	pos(&rb->b);
	if (flag)
		write(1, "rb\n", 3);
}

void	rab(t_list *ra, int flag)
{
	ra->a.top = ra->a.top->next;
	pos(&ra->a);
	ra->b.top = ra->b.top->next;
	pos(&ra->b);
	if (flag)
		write(1, "rr\n", 3);
}
