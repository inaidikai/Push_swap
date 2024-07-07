/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_cmds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:22:23 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:52:48 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cmds_total(t_list *stacks, t_cmds *cmd)
{
	int	i;

	cmd->cmd_total[0] = cmd->step_a[0];
	i = 1;
	while (i < stacks->b.length)
	{
		if ((!ft_strncmp(cmd->cmd_a[i], "ra", 100) && \
				!ft_strncmp(cmd->cmd_b[i], "rb", 100)) || \
			(!ft_strncmp(cmd->cmd_a[i], "rra", 100) && \
				!ft_strncmp(cmd->cmd_b[i], "rrb", 100)))
		{
			if (cmd->step_a[i] > cmd->step_b[i])
				cmd->cmd_total[i] = cmd->step_a[i];
			else
				cmd->cmd_total[i] = cmd->step_b[i];
		}
		else if ((!ft_strncmp(cmd->cmd_a[i], "ra", 100) && \
					!ft_strncmp(cmd->cmd_b[i], "rrb", 100)) || \
					(!ft_strncmp(cmd->cmd_a[i], "rra", 100) && \
					!ft_strncmp(cmd->cmd_b[i], "rb", 100)))
			cmd->cmd_total[i] = cmd->step_a[i] + cmd->step_b[i];
		else if (!cmd->cmd_a[i])
			cmd->cmd_total[i] = cmd->step_b[i];
		i++;
	}
}

void	find_min_commands(t_list *stacks, t_cmds *cmd)
{
	int	i;
	int	cmd_min;

	cmd_min = cmd->cmd_total[0];
	cmd->index = 0;
	i = 1;
	while (i < stacks->b.length)
	{
		if (cmd->cmd_total[i] < cmd_min)
		{
			cmd_min = cmd->cmd_total[i];
			cmd->index = i;
		}
		i++;
	}
}

void	get_min_commands(t_cmds *cmd)
{
	if ((!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100) && \
			!ft_strncmp(cmd->cmd_b[cmd->index], "rb", 100)) || \
		(!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100) && \
			!ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 100)))
	{
		if (cmd->step_a[cmd->index] > cmd->step_b[cmd->index])
		{
			cmd->do_a = cmd->step_a[cmd->index] - cmd->step_b[cmd->index];
			cmd->do_ab = cmd->step_b[cmd->index];
		}
		else
		{
			cmd->do_b = cmd->step_b[cmd->index] - cmd->step_a[cmd->index];
			cmd->do_ab = cmd->step_a[cmd->index];
		}
	}
	else
	{
		cmd->do_a = cmd->step_a[cmd->index];
		cmd->do_b = cmd->step_b[cmd->index];
	}
}

void	execute_min_commands(t_list *stacks, t_cmds *cmd)
{
	while (cmd->do_a)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100))
			ra(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100))
			rra(stacks, 1);
		cmd->do_a--;
	}
	while (cmd->do_b)
	{
		if (!ft_strncmp(cmd->cmd_b[cmd->index], "rb", 100))
			rb(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_b[cmd->index], "rrb", 100))
			rrb(stacks, 1);
		cmd->do_b--;
	}
	while (cmd->do_ab)
	{
		if (!ft_strncmp(cmd->cmd_a[cmd->index], "ra", 100))
			rab(stacks, 1);
		else if (!ft_strncmp(cmd->cmd_a[cmd->index], "rra", 100))
			rrr(stacks, 1);
		cmd->do_ab--;
	}
}
