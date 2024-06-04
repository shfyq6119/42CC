/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 22:30:21 by mm-isa            #+#    #+#             */
/*   Updated: 2024/04/29 20:41:46 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
/*this pathing must always be from where the header file lives*/

typedef	enum
{
	A = 65,
	B = 66
}	e_id;

typedef struct t_limits
{
	int				min_a;
	int				min_b;
	int				max_a;
	int				max_b;
}	t_limits;

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

typedef struct t_cost
{
	int				cost;
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
}	t_cost;

typedef struct t_stack
{
	long			nb;
	e_id			id;
	struct t_stack	*next;
}	t_stack;

typedef struct t_meta
{
	t_stack			*head_a;
	t_stack			*head_b;
	t_cmd			*moves;
	t_cost			*cost;
	t_limits		*limits;
}	t_meta;

/*******************************intake processing******************************/
void		dupchk(t_stack *head);
void		inting_check(int ac, char **av);
void		argcheck(int ac, char **av);
void		handle_error(void);
/*********************************stack parsing********************************/
t_stack		*stackparse(int ac, char **av);
t_stack		*ft_stack_new(int content);
t_stack		*ft_stklast(t_stack *a);
void		ft_stk_add_last(t_stack **a, t_stack *add);
int			ft_stk_size(t_stack	*head);
int			ft_atoi_lbrk(char *str);
/*********************************stack presorts*******************************/
void		chp2gd2(t_meta *motherstack);
void		cheapest_check(t_cmd *lowest, t_cmd *moveset, int flag);
void		check_cmds(t_meta *motherstack);
void		init_limits(t_meta *motha, t_limits *range);
void		limit_stackcheck(t_meta *motha);
void		limit_check_a(t_meta *motha, t_stack *a);
void		limit_check_b(t_meta *motha, t_stack *b);
void		median_rotcost(int *revrot, int *rottate, int size, int idx);
void		pushcost_rotcalc(t_meta *motha, t_stack *a, int idx);
void		pushsort_calc(t_meta *motha, int num);
void		rotab_dupcheck(t_cmd *moves);
void		rotcost_calc(t_stack *node, t_cmd *moveset, int size, int idx);
void		stackcheapest(t_meta *motherstack);
void		sortstack(t_meta *motherstack);
int			sortcheck(t_meta *motherstack);
/***********************************stacksorts*********************************/
void		rotate(t_meta *motha);
void		revrot(t_meta *motha);
void		push(t_meta *motha);
void		swap(t_stack *header);
void		sort3(t_meta *motherstack);
void		sort4(t_meta *motherstack);
void		restore_sorted(t_meta *motherstack);

/***********************************cleanup************************************/
void		ff_gg(t_meta *motha);
#endif