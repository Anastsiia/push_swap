/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctifany <ctifany@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 21:22:46 by ctifany           #+#    #+#             */
/*   Updated: 2021/10/12 21:29:06 by ctifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_arg
{
	int				num;
	int				index;
	struct s_arg	*next;
	struct s_arg	*back;
	int				place;
}					t_arg;

typedef struct s_anb
{
	struct s_arg	*a;
	struct s_arg	*b;
}					t_anb;

long		ft_atoi(const char *str);
t_arg		*ft_lstnew(int num, int index);
void		ft_lstadd_back(t_arg **lst, t_arg *num);
int			ft_lstsize(t_arg *lst);
static void	ft_push(t_arg **target, t_arg **source);
void		ft_p(t_anb *stack, char c);
static void	ft_rotate_r(t_arg **list);
static void	ft_rotate(t_arg **lst);
void		ft_rr(t_anb *stack, char c);
void		ft_r(t_anb *stack, char c);
char		**ft_error(char **res);
int			ft_count_w(const char *s, char c);
int			ft_len_w(const char *s, char c, int i);
char		**ft_write_w(char const *s, char c, char **res, int count);
char		**ft_split(char const *s, char c);
static void	ft_swap(t_arg **list, t_arg *second);
void		ft_s(t_anb *stack, char c);
void		ft_fill_index(t_arg *a, int len);
int			ft_check_sort(t_arg *tmp);
int			ft_check_double(t_arg *tmp, long num);
void		ft_create_stack(t_anb *stack);
static void	ft_three_sort(t_arg *one, t_arg *two, t_arg *three, t_anb *stack);
static void	ft_six_sort(t_anb *stack, int len);
void		ft_all_sort(t_anb *stack, int count);
void		ft_sort_stack(t_anb *stack);
static int	ft_tob(t_anb *stack, int index, int place);
int			ft_add_place(int *place, t_arg *temp, int index);
static void	ft_toa_split(t_anb *stack, int mid, int *index, int place);
static int	ft_tob(t_anb *stack, int index, int place);
static int	ft_toa_last(t_anb *stack, int index);
static void	ft_tob_first(t_anb *stack, int mid, int index);
void		ft_find(t_anb *stack, t_arg *temp, int index);

#endif