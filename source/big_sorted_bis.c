/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sorted_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:47:54 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 14:28:52 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	this_is_a_zero(char *binary, int nb)
{
	if (binary[nb] == '0')
		return (0);
	return (1);
}

void	sorted_binary(t_col **index)
{
	int		i;
	int		f;

	i = (str_nbr((*index)->len_a) - 2);
	f = 0;
	while (i > -1)
	{
		f = 0;
		while (f < (*index)->argc)
		{
			if (this_is_a_zero((*index)->col_a->binary, i) == 0)
				push(index, 1);
			else
				rotate(index, 1);
			f++;
		}
		while ((*index)->len_b != 0)
			push(index, 2);
		i--;
	}
}

void	free_binary(t_col **index)
{
	t_num	*tmp;

	tmp = (*index)->col_a;
	while (tmp && tmp->binary)
	{
		free(tmp->binary);
		tmp = tmp->next;
	}
}
