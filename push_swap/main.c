/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 00:49:21 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/19 15:49:03 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	issorted(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !stack->top)
	{
		return (1);
	}
	current = stack->top;
	next = current->next;
	while (next != stack->top)
	{
		if (current->data > next->data)
		{
			return (0);
		}
		current = next;
		next = next->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	list;

	initialize(&list);
	if ((store(argc, argv, &list.a)) == 1)
	{
		if (!issorted(&list.a))
		{
			pushswap(&list);
		}
	}
	free_stack(&list.a);
	free_stack(&list.b);
}
