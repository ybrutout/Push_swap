/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:11:10 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 14:49:34 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_number
{
	int				nb;
	int				indx;
	char			*binary;
	struct s_number	*next;
}					t_num;

typedef struct s_column
{
	struct s_number	*col_a;
	struct s_number	*col_b;
	int				max_a;
	int				min_a;
	int				max_b;
	int				min_b;
	int				min;
	int				max;
	int				argc;
	int				len_a;
	int				len_b;
	int				last_a;
	int				last_b;
	int				stack;
}					t_col;

//error
void	ft_error_message(t_col **index, int nb);

//operation

void	swap_button(t_col **index, int button);
void	push(t_col **index, int button);
void	rotate(t_col **index, int button);
void	reverse_rot(t_col **index, int button);

//ft_libft

int		ft_atoi(const char *str, t_col **index);
t_num	*ft_lstnew(int *content);
t_num	*ft_lstadd_back(t_num *alst, t_num *new);
int		ft_lstsize(t_num *lst);
void	ft_lstclear(t_num **lst);

//ft_libft_second

char	*ft_strcat(char *str, char *buffer);
int		ft_compare(t_col **index, char *line);

//sorted
int		sorted(t_col **index, int **lst_sort);
int		position_for(t_num *col, int nb);
int		middlepoint(t_col **index, int **lst_sort);

//index
t_col	*int_new_index(int nb, char **argv);
void	change_index(t_col **index);
int		nb_max(t_num **col_a, int len);
int		nb_min(t_num **col_a, int len);
int		last_nb(t_num *col, int	len);

//toolbox
void	ft_write(int button, t_col **index);
int		free_lst(t_num *alst);

//toolbox_2
int		nb_second_max(t_num **col, int len, int max);
int		ascending(t_col **index);
int		decreasing(t_num *col_b, int len);

//toolbox_3
int		*nw_lst_order(t_num **col, int *lst_new, int len, int knob);

//little_sort

void	sorted_3(t_col **index);
void	sorted_5(t_col **index, int **lst_sort);

//big sorted
int		big_sorted(t_col **index, int **lst_sort);
int		str_nbr(int nb);

//big_sorted_bis
void	sorted_binary(t_col **index);
void	free_binary(t_col **index);

//operation_biss
void	rotate_bis(t_col **index, int nb);
void	reverse_rott_biss(t_col **index, int len, int nb);

//position
int		position_for(t_num *col, int nb);
int		position(t_col **index, t_num *col, int len, int middle);

//middlepoint
int		middlepoint_first(t_col **index, int **lst_sort);
int		middlepoint(t_col **index, int **lst_sort);

//both_utils
int		check_arg(int argc, char **argv);
int		parsing(char **argv, t_col **index);

//operation_checker
void	ch_swap_button(t_col **index, int button);
void	ch_push(t_col **index, int button);
void	ch_rotate(t_col **index, int button);
void	ch_reverse_rot(t_col **index, int button);

//operation_checker_biss
void	ch_rotate_bis(t_col **index, int nb);
void	ch_reverse_rott_biss(t_col **index, int len, int nb);

//checker
void	ft_operation(t_col **index, int nb);

#endif
