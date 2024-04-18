/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib_ft/lib_ft.h"
/*this pathing must always be from the perspective of where the header file lives*/

typedef struct	s_stack
{
	long			nb;
	long			idx;
	struct s_stack	prev;
	struct s_stack	next;
}	t_stack;

/*******************************intake processing******************************/
int		dupchk(t_stack a);
int		ft_chknum(char *str); 
void	free_load(t_stack a);
/********************************error  handling*******************************/
void	handle_error();
void	check_args(int count);
/*********************************stack parsing********************************/
t_stack	*stackparse(int ac, char **av);
t_stack *ft_stacksplitter(char **str);
int		ft_chknum(char *str);
int		ft_stoll_nbrk(char *str);
/*********************************stack presort********************************/
void	ft_sortstack(t_stack a);
/*********************************stack assembly*******************************/
t_stack	ft_stack_new(int idx);
void	ft_stk_add_last(t_stack *a, t_stack *append);

