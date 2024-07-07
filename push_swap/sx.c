/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:07:58 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:47:58 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *sa, int flag)
{
	int	a;
	int	b;

	a = reup(&sa->a);
	b = reup(&sa->a);
	push(&sa->a, a);
	push(&sa->a, b);
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_list *sa, int flag)
{
	int	a;
	int	b;

	a = reup(&sa->b);
	b = reup(&sa->b);
	push(&sa->b, a);
	push(&sa->b, b);
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_list *sa, int flag)
{
	int	a;
	int	b;

	a = reup(&sa->b);
	b = reup(&sa->b);
	push(&sa->b, a);
	push(&sa->b, b);
	a = reup(&sa->a);
	b = reup(&sa->a);
	push(&sa->a, a);
	push(&sa->a, b);
	if (flag)
		write(1, "ss\n", 2);
}
