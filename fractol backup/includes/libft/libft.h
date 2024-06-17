/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:06:17 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/23 18:05:03 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>

# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

int			ft_atoi(const char *n);
void		ft_bzero(void *schitt, size_t is_nasty);
void		*ft_calloc(size_t elem, size_t bytes);
void        ft_free(void **ptr);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int c);
void		*ft_memchr(const void *mem, int find, size_t bytes);
int			ft_memcmp(const void *m1, const void *m2, size_t match);
void		*ft_memcpy(void *desu, const void *sos, size_t load);
void		*ft_memmove(void *desu, const void *sos, size_t nahh);
void		*ft_memset(void *mem, int set, size_t num);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *string, int fd);
void		ft_putnbr_fd(int number, int fd);
void		ft_putstr_fd(char *string, int fd);
char		**ft_split(char const *splot, char splet);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(char const *prefix, char const *suffix);
size_t		ft_strlcat(char *desu, const char *src, size_t slimit);
size_t		ft_strlcpy(char *desu, const char *src, size_t slimit);
size_t		ft_strlen(const char *str);
char		*ft_strmapi(char const *give, char (*fn)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t i);
char		*ft_strnstr(const char *big, const char *smol, size_t schlong);
char		*ft_strrchr(const char *search, int c);
char		*ft_strtrim(char const *str, char const *trash);
void		ft_striteri(char *str, void (*fn)(unsigned int, char *));
char		*ft_substr(char const *str, unsigned int start, size_t schlongth);
int			ft_tolower(int c);
int			ft_toupper(int c);
void		ft_lstadd_back(t_list **ls_node, t_list *node_add);
void		ft_lstadd_front(t_list **ls_node, t_list *node_zero);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *list, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*fn)(void *));
t_list		*ft_lstlast(t_list *node_zero);
t_list		*ft_lstmap(t_list *list, void *(*fn)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *ls_nodes);
int         ft_printf(const char *format, ...);
int         ft_putchar_n(char c);
int          ft_putstr_n(char *s);
int          ft_putnbr_n(long i);
int          ft_putaddr_n(unsigned long p);
int          ft_puthex_n(unsigned long h, char *hexcase);

#endif
