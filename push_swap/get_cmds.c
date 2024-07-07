/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:23:31 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/12 12:40:31 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_if_max(t_list *stacks, t_cmds *cmd, int max, int i)
{
	int	index;

	index = get_index(stacks->a, max);
	if (index < stacks->a.length / 2)
	{
		cmd->step_a[i] = index + 1;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->a.length - index - 1;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_if_min(t_list *stacks, t_cmds *cmd, int min, int i)
{
	int	index;

	index = get_index(stacks->a, min);
	if (index <= stacks->a.length / 2)
	{
		cmd->step_a[i] = index;
		cmd->cmd_a[i] = "ra";
	}
	else
	{
		cmd->step_a[i] = stacks->a.length - index;
		cmd->cmd_a[i] = "rra";
	}
}

static void	ft_if_between(t_list *stacks, t_cmds *cmd, int i, t_stack tmp_b)
{
	int		j;
	t_node	*tmp;

	j = 0;
	tmp = stacks->a.top;
	while (j < stacks->a.length - 1)
	{
		if (tmp_b.top->data > tmp->data && tmp_b.top->data < tmp->next->data)
		{
			if (j < stacks->a.length / 2)
			{
				cmd->step_a[i] = j + 1;
				cmd->cmd_a[i] = "ra";
			}
			else
			{
				cmd->step_a[i] = stacks->a.length - (j + 1);
				cmd->cmd_a[i] = "rra";
			}
			j = stacks->a.length;
		}
		tmp = tmp->next;
		j++;
	}
}

void	get_cmds_a(t_list *stacks, t_cmds *cmd)
{
	int		i;
	int		mi;
	int		max;
	t_stack	tmp_b;

	tmp_b = stacks->b;
	i = -1;
	while (++i < stacks->b.length)
	{
		max = find_max(stacks);
		mi = min(stacks);
		if (tmp_b.top->data > max)
			ft_if_max(stacks, cmd, max, i);
		else if (tmp_b.top->data < mi)
			ft_if_min(stacks, cmd, mi, i);
		else
			ft_if_between(stacks, cmd, i, tmp_b);
		if (cmd->step_a[i] == 0)
			cmd->cmd_a[i] = NULL;
		tmp_b.top = tmp_b.top->next;
	}
}

void	get_cmds_b(t_list *stacks, t_cmds *cmd)
{
	int	i;

	i = 0;
	while (++i < stacks->b.length)
	{
		if (i <= stacks->b.length / 2)
		{
			cmd->step_b[i] = i;
			cmd->cmd_b[i] = "rb";
		}
		else
		{
			cmd->step_b[i] = stacks->b.length - i;
			cmd->cmd_b[i] = "rrb";
		}
	}
	if (stacks->b.length % 2 == 0)
		if (!ft_strncmp(cmd->cmd_a[stacks->b.length / 2], "rra", 100))
			cmd->cmd_b[stacks->b.length / 2] = "rrb";
}
