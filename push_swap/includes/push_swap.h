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
	A,
	B
}	e_id;

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
	long			idx;
	struct t_stack	*prev;
	struct t_stack	*next;
	e_id			id;
}	t_stack;

/***to reconsider metadata structure for util trimming; map out boolean flows**/
/**flowchart? control flow logic takes boolean (A or B) nature; utils don't  **/
/****need duplicates if all they do is the same action on two diff elements****/

typedef struct t_metastack
{
	struct t_stack	*head_a;
	struct t_stack	*head_b;
	struct t_meta	*limits;
	struct t_cmd	*moves;
	struct t_cost	*cost;
}	t_metastack;

/*******************************intake processing******************************/
int		dupchk(t_stack *a);
/********************************error  handling*******************************/
void	handle_error();
int		check_args(int count);
/*********************************stack parsing********************************/
t_stack	*stackparse(int ac, char **av);
t_stack	*ft_stacksplitter(char **str);
int		ft_chknum(char *str);
int		ft_atoi_nbrk(char *str);
/*********************************stack presort********************************/
void	ft_sortstack(t_metastack *motha);
int		ft_sortchk(t_stack *a);
/*********************************stack assembly*******************************/
t_stack	*ft_stack_new(int idx);
void	ft_stk_add_last(t_stack *a, t_stack *add);
/***********************************cleanup************************************/
void	free_array(char **str);
void	free_load(t_metastack *a);
#endif
