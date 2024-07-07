/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inkahar <inkahar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:21:31 by inkahar           #+#    #+#             */
/*   Updated: 2024/06/15 13:15:07 by inkahar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	int				pos;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				length;
}					t_stack;

typedef struct s_list
{
	t_stack			a;
	t_stack			b;
}					t_list;

typedef struct s_cmds
{
	int				do_a;
	int				do_b;
	int				do_ab;
	int				index;
	int				*step_a;
	int				*step_b;
	int				*cmd_total;
	char			**cmd_a;
	char			**cmd_b;
}					t_cmds;

char				**ft_split(char const *s, char c);
void				inistack(t_stack *stack);
void				initialize(t_list *list);
int					check(char **c, t_stack *a);
int					dupli(t_stack *list, int data);
long				ft_atoi(const char *str);
int					ft_isdigit(int c);
int					store(int argc, char **argv, t_stack *a);
int					main(int argc, char **argv);
void				fry(char **c);
int					reup(t_stack *stack);
void				pos(t_stack *a);
void				push(t_stack *a, int i);
int					find_max(t_list *stack);
int					min(t_list *stack);
void				pushswap(t_list *list);
void				*ft_calloc(size_t count, size_t size);
void				start_sorting(t_list *stacks, t_cmds *cmd);
void				get_cmds_a(t_list *stacks, t_cmds *cmd);
void				get_cmds_b(t_list *stacks, t_cmds *cmd);
void				get_cmds_total(t_list *stacks, t_cmds *cmd);
void				find_min_commands(t_list *stacks, t_cmds *cmd);
void				get_min_commands(t_cmds *cmd);
void				execute_min_commands(t_list *stacks, t_cmds *cmd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					get_index(t_stack stack, int list);
void				init_cmd(t_cmds *cmd);
void				free_stack(t_stack *stack);
int					is_numeric(const char *str);
int					spacchk(char *argv);
void				ss(t_list *sa, int flag);
void				sb(t_list *sa, int flag);
void				sa(t_list *sa, int flag);
void				pb(t_list *list, int flag);
void				pa(t_list *list, int flag);
void				rra(t_list *rra, int flag);
void				rrb(t_list *rrb, int flag);
void				rrr(t_list *rrb, int flag);
void				ra(t_list *ra, int flag);
void				rb(t_list *rb, int flag);
void				rab(t_list *ra, int flag);
void				ft_read_cmds(t_list *stacks);
void				ft_do_cmds(t_list *stacks, char *line);
void				ft_error(void);

#endif