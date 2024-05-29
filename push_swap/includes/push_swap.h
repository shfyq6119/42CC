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
/*********************************stack parsing******************************/
t_stack		*stackparse(int ac, char **av);
t_stack		*ft_stack_new(int content);
t_stack		*ft_stklast(t_stack *a);
//t_stack		*stackparse_b(int ac, char **av);
//t_stack		*ft_stack_new_b(int content);
void		ft_stk_add_last(t_stack **a, t_stack *add);
//void		ft_free_stack(t_stack stk_a, t_stack stk_b);
int			ft_atoi_lbrk(char *str);
/*********************************stack presort********************************
void		ft_sortstack(t_meta *motha);
int			ft_sortchk(t_meta *a);
***********************************cleanup***********************************
void		free_array(char **str);
void		free_load(t_meta *a);*/
#endif
