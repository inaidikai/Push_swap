/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:03:20 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 11:51:57 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stacks)
{
	t_node	*current;
	t_node	*start;
	int		max_value;

	if (stacks == NULL || stacks->a.top == NULL)
	{
		printf("Error: stack is empty or uninitialized.\n");
		return (INT_MIN);
	}
	current = stacks->a.top;
	max_value = current->data;
	start = current;
	current = current->next;
	while (current != start)
	{
		if (current->data > max_value)
		{
			max_value = current->data;
		}
		current = current->next;
	}
	return (max_value);
}

int	min(t_list *stack)
{
	t_node	*current;
	t_node	*start;
	int		min_value;

	if (stack == NULL || stack->a.top == NULL)
	{
		printf("Error: stack is empty or uninitialized.\n");
		return (INT_MAX);
	}
	current = stack->a.top;
	min_value = current->data;
	start = current;
	current = current->next;
	while (current != start)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
		}
		current = current->next;
	}
	return (min_value);
}

static void	init_cmds(t_list *stacks, t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = (int *)ft_calloc(sizeof(int), stacks->b.length);
	cmd->step_b = (int *)ft_calloc(sizeof(int), stacks->b.length);
	cmd->cmd_a = (char **)ft_calloc(sizeof(char *), stacks->b.length);
	cmd->cmd_b = (char **)ft_calloc(sizeof(char *), stacks->b.length);
	cmd->cmd_total = (int *)ft_calloc(sizeof(int), stacks->b.length);
	if (!(cmd->step_a && cmd->step_b && \
			cmd->cmd_a && cmd->cmd_b && cmd->cmd_total))
		exit(1);
}

void	start_sorting(t_list *stacks, t_cmds *cmd)
{
	while (stacks->b.length)
	{
		init_cmds(stacks, cmd);
		get_cmds_a(stacks, cmd);
		get_cmds_b(stacks, cmd);
		get_cmds_total(stacks, cmd);
		find_min_commands(stacks, cmd);
		get_min_commands(cmd);
		execute_min_commands(stacks, cmd);
		pa(stacks, 1);
		free(cmd->step_a);
		free(cmd->step_b);
		free(cmd->cmd_a);
		free(cmd->cmd_b);
		free(cmd->cmd_total);
	}
}
