/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:30:21 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/25 22:33:15 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../lib_ft/lib_ft.h"
/*this pathing must always be from the where the header file lives*/

typedef struct s_stack_a
{
	long			nb;
	long			idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack_a;

typedef struct s_stack_b;
{
	long			nb;
	long			idx;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack_b;

typedef struct t_stkmeta
{
	struct t_stack	*head_a;
	struct t_stack	*head_b;
	struct t_meta	*limits;
	struct t_cmd	*moves;
	struct t_cost	*cost;
}	t_stkmeta;

typedef struct t_meta
{
	int				min_a;
	int				min_b;
	int				max_a;
	int				max_b;
}	t_meta;

typedef struct t_cmd
{
	int				count;
	int				pa;
	int				pb;
	int				sa;
	int				sb;
	int				ss;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}	t_cmd;


/*******************************intake processing******************************/
int		dupchk(t_stack_a *a);
void	free_load(t_stack a);
/********************************error  handling*******************************/
//void	handle_error();
void	check_args(int count, char **str);
/*********************************stack parsing********************************/
t_stack	*stackparse(int ac, char **av);
t_stack	*ft_stacksplitter(char **str);
int		ft_chknum(char *str);
int		ft_atoi_nbrk(char *str);
/*********************************stack presort********************************/
void	ft_sortstack(t_stack a);
int		ft_sortchk(t_stack a);
/*********************************stack assembly*******************************/
t_stack	ft_stack_new(int idx);
void	ft_stk_add_last(t_stack *a, t_stack *append);
#endif
