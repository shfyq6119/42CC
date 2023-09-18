/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-isa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:06:17 by mm-isa            #+#    #+#             */
/*   Updated: 2023/09/13 23:48:08 by mm-isa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}					t_list;*/

int			ft_atoi(const char *n);
void		ft_bzero(void *schitt, size_t is_nasty);
void		*ft_calloc(size_t elem, size_t bytes);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
/*char		*ft_itoa(int n);*/
void		*ft_memchr(const void *mem, int find, size_t bytes);
int			ft_memcmp(const void *m1, const void *m2, size_t match);
void		*ft_memcpy(void *desu, const void *sos, size_t load);
void		*ft_memmove(void *desu, const void *sos, size_t nahh);
void		*ft_memset(void *mem, int set, size_t num);
/*void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);*/
char		**ft_split(char const *s, char c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *desu, const char *src, size_t slimit);
size_t		ft_strlcpy(char *desu, const char *src, size_t slimit);
size_t		ft_strlen(const char *str);
/*char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));*/
int			ft_strncmp(const char *s1, const char *s2, size_t i);
char		*ft_strnstr(const char *big, const char *schmol, size_t schlong);
char		*ft_strrchr(const char *s, int a);
/*char		*ft_strtrim(char const *s1, char const *set);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_substr(char const *s, unsigned int start, size_t len);*/
int			ft_tolower(int c);
int			ft_toupper(int c);

/*Bonus

int					ft_lstsize(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*ft_lstnew(void *content);*/

#endif
