/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:21:58 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/09 17:22:03 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*malllo(t_node *g)
{
	g = (t_node *)malloc(sizeof(t_node));
	g->next = NULL;
	g->prev = NULL;
	g->data = 0;
	return (g);
}

static void	push2(t_stack *a, t_node *b)
{
	if (a->top)
	{
		b->next = a->top;
		if (a->top->next == a->top)
		{
			b->prev = a->top;
			a->top->next = b;
			a->top->prev = b;
		}
		else
		{
			b->prev = a->top->prev;
			a->top->prev->next = b;
			a->top->prev = b;
		}
	}
	else
	{
		b->next = b;
		b->prev = b;
	}
	a->top = b;
	a->length++;
}

void	pos(t_stack *a)
{
	t_node	*b;
	int		i;

	if (!a || !a->top)
		return ;
	i = 0;
	b = a->top;
	while (42)
	{
		b->pos = i++;
		b = b->next;
		if (b == a->top)
			break ;
	}
}

void	push(t_stack *a, int i)
{
	t_node	*b;

	b = NULL;
	b = malllo(b);
	b->data = i;
	push2(a, b);
	pos(a);
}
