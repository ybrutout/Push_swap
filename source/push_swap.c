/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:10:31 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 14:35:56 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	choose_sort(t_col **index, int **lst_sort, int nb)
{
	if (nb <= 3)
		sorted_3(index);
	else if (nb <= 5)
		sorted_5(index, lst_sort);
	else if (nb <= 200)
	{
		if (sorted(index, lst_sort) == 0)
			return (0);
	}
	else
		if (big_sorted(index, lst_sort) == 0)
			return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		*lst_sort;
	t_col	*index;

	if (argc < 2)
		return (0);
	if (check_arg(argc, argv) != 1)
		return (0);
	index = int_new_index((argc - 1), argv);
	if (!index)
		return (write(1, "Error\n", 6));
	if (ascending(&index) == 1 || argc == 2)
	{
		free_lst(index->col_a);
		free(index);
		return (1);
	}
	choose_sort(&index, &lst_sort, index->argc);
	free_lst(index->col_a);
	free_lst(index->col_b);
	free(lst_sort);
	free(index);
	return (1);
}
