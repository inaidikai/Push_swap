/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:54:47 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 16:51:45 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_do_cmds(t_list *stacks, char *line)
{
	if (!ft_strncmp(line, "sa", 100))
		sa(stacks, 0);
	else if (!ft_strncmp(line, "sb", 100))
		sb(stacks, 0);
	else if (!ft_strncmp(line, "ss", 100))
		ss(stacks, 0);
	else if (!ft_strncmp(line, "pa", 100))
		pa(stacks, 0);
	else if (!ft_strncmp(line, "pb", 100))
		pb(stacks, 0);
	else if (!ft_strncmp(line, "ra", 100))
		ra(stacks, 0);
	else if (!ft_strncmp(line, "rb", 100))
		rb(stacks, 0);
	else if (!ft_strncmp(line, "rr", 100))
		rab(stacks, 0);
	else if (!ft_strncmp(line, "rra", 100))
		rra(stacks, 0);
	else if (!ft_strncmp(line, "rrb", 100))
		rrb(stacks, 0);
	else if (!ft_strncmp(line, "rrr", 100))
		rrr(stacks, 0);
	else
		ft_error();
}

void	ft_read_cmds(t_list *stacks)
{
	char	*line;

	line = get_next_line(0);
	while ((line))
	{
		ft_do_cmds(stacks, line);
		free(line);
		line = NULL;
		line = get_next_line(0);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
}

static int	issorted(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	next = current->next;
	while (next != stack->top)
	{
		if (current->data > next->data)
			return (0);
		current = next;
		next = next->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	list;

	if (argc < 2)
		return (0);
	initialize(&list);
	if (store(argc, argv, &list.a) == 1)
	{
		ft_read_cmds(&list);
		if (issorted(&list.a) && !list.b.length)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(&list.a);
	free_stack(&list.b);
	return (0);
}
