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


