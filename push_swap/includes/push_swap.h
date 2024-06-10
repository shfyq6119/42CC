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
# define FLAG_A (1 << 2)
# define FLAG_B (1 << 3)
# define FLAG_RR (1 << 16)
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define NULL ((void*)0)

# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../includes/libft/libft.h"
/*this pathing must always be from where the header file lives*/

typedef	enum
{
	A = 1 << 0,
	B = 1 << 1
}	e_id;

typedef struct t_limits
{
	long			min_a;
	long			min_b;
	long			max_a;
	long			max_b;
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
void		dupcheck(int ac, char **av);
void		inting_check(int ac, char **av);
void		argcheck(int ac, char **av);
void		handle_error(void);
/*********************************stack parsing********************************/
t_stack		*stackparse(int ac, char **av);
t_stack		*ft_stack_new(int content);
t_stack		*ft_stklast(t_stack *a);
t_stack		*ft_stkpenultimate(t_stack *head);
void		ft_stk_add_last(t_stack **a, t_stack *add);
int			ft_stk_size(t_stack	*head);
int			ft_atoi_lbrk(char *str);
/*********************************stack presorts*******************************/
void	chp2gd2(t_meta *motherstack);
void	cheapest_check(t_cost *lowest, t_cmd *moveset, int flag);
void	check_cmds(t_meta *motherstack);
void	flag_nodes(t_stack *stack, int flag, int *count);
void	init_limits(t_meta *motha, t_limits *range);
void	limit_check(long *min, long *max, t_stack *head);
void	median_rotcost(int *revrot, int *rottate, int size, int idx);
void	median_rotmax(t_meta *mother, int size, int idx);
void	pushcost_rotcalc(t_meta *motha, t_stack *a, int idx);
void	pushsort_calc_a(t_meta *motha, long *num);
void	pushsort_calc_b(t_meta *motha, long *num);
void	rot_preprocessor(t_meta *motha);
void	rot_postprocessor(t_meta *motha);
void	rotab_dupcheck(t_cmd *moves);
void	stackcheapest(t_meta *motherstack);
void	sortstack(t_meta *motherstack);
int		findex(t_stack *head, long num);
int		find_nextnum(t_stack *head, long num);
int		sortcheck(t_meta *motherstack);
/***********************************stacksorts*********************************/
void	sub_rot(t_stack **head1, t_stack **head2, t_stack *ptr1, t_stack *ptr2);
void	rotate(t_stack **head1, t_stack **head2);
void	revrot(t_stack **head1, t_stack **head2, t_stack *ptr1, t_stack *ptr2);
void	push_module(t_meta *motha);
void	rot_module(t_meta *motha);
void	first_push(t_stack **ptr1, t_stack **ptr2);
void	push(t_stack **ptr1, t_stack **ptr2);
void	last_push(t_stack **ptr1, t_stack **ptr2);
void	swap(t_stack **header);
void	sort3(t_meta *motherstack);
void	sort4(t_meta *motherstack);
void	tinysortflag(t_meta *motha, int first, int second, int third);
void	restore_sorted(t_meta *motherstack);
/********************************postsort & cleanup****************************/
void	deflag(t_stack *node1);
void	ff_gg(t_meta *motha);
void	ffs(t_meta *motha);
void	finish(t_meta *motha);
void	clean_costs(t_meta *motha);
#endif
