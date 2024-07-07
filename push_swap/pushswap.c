/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:20:36 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/23 11:25:13 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*buff;

	if (!stack || !stack->top)
		return ;
	tmp = NULL;
	while (tmp != stack->top)
	{
		if (!tmp)
			tmp = stack->top;
		buff = tmp;
		tmp = tmp->next;
		free(buff);
	}
	return ;
}

static void	smallsort(t_list *stacks)
{
	int		max;
	t_list	*c;

	c = stacks;
	max = find_max(c);
	if (stacks->a.length == 1)
		return ;
	if (stacks->a.length == 2)
	{
		if (stacks->a.top->data > stacks->a.top->next->data)
		{
			sa(stacks, 1);
			return ;
		}
	}
	else if (stacks->a.length == 3)
	{
		if (stacks->a.top->data == max)
			ra(stacks, 1);
		else if (stacks->a.top->next->data == max)
			rra(stacks, 1);
		if (stacks->a.top->data > stacks->a.top->next->data)
			sa(stacks, 1);
	}
}

static void	five(t_list *list)
{
	int	i;
	int	mi;
	int	max;

	i = list->b.length;
	mi = min(list);
	max = find_max(list);
	while (list->b.length - i != 2)
	{
		if (list->a.top->data == mi || list->a.top->data == max)
			pb(list, 1);
		else
			ra(list, 1);
	}
	smallsort(list);
	pa(list, 1);
	pa(list, 1);
	if (list->a.top->data == max)
		ra(list, 1);
	else
	{
		sa(list, 1);
		ra(list, 1);
	}
}

static void	large(t_list *stacks, t_cmds *cmd)
{
	int	mi;
	int	index_of_min;

	while (stacks->a.length > 5)
		pb(stacks, 1);
	five(stacks);
	start_sorting(stacks, cmd);
	mi = min(stacks);
	index_of_min = get_index(stacks->a, mi);
	while (stacks->a.top->data != mi)
	{
		if (index_of_min <= stacks->a.length / 2)
			ra(stacks, 1);
		else
			rra(stacks, 1);
	}
}

void	pushswap(t_list *list)
{
	t_cmds	cmd;

	init_cmd(&cmd);
	if (list->a.length <= 3)
		smallsort(list);
	else if (list->a.length <= 5)
		five(list);
	else
		large(list, &cmd);
}
