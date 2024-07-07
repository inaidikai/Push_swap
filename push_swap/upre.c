/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upre.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:07:31 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 16:32:37 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	up(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	if (stack->top == stack->top->next)
	{
		stack->top = NULL;
	}
	else
	{
		if (stack->top->next == stack->top->prev)
		{
			stack->top->next->next = stack->top->next;
			stack->top->prev->prev = stack->top->prev;
		}
		else
		{
			stack->top->next->prev = stack->top->prev;
			stack->top->prev->next = stack->top->next;
		}
		stack->top = stack->top->next;
	}
	free(temp);
	stack->length--;
}

int	reup(t_stack *stack)
{
	int	data;

	if (!stack || !stack->top)
	{
		return (-1);
	}
	data = stack->top->data;
	up(stack);
	pos(stack);
	return (data);
}

void	init_cmd(t_cmds *cmd)
{
	cmd->do_a = 0;
	cmd->do_b = 0;
	cmd->do_ab = 0;
	cmd->index = 0;
	cmd->step_a = 0;
	cmd->step_b = 0;
	cmd->cmd_total = 0;
	cmd->cmd_a = NULL;
	cmd->cmd_b = NULL;
}

void	inistack(t_stack *stack)
{
	if (!stack)
	{
		exit(1);
	}
	stack->length = 0;
	stack->top = NULL;
}

void	initialize(t_list *list)
{
	if (!list)
	{
		exit(1);
	}
	inistack(&list->a);
	inistack(&list->b);
}
