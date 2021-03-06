/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox_third.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybrutout <ybrutout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 14:02:36 by ybrutout          #+#    #+#             */
/*   Updated: 2021/08/02 14:41:21 by ybrutout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	ft_order(int **lst_sort, int argc)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	while (i < argc)
	{
		if ((i + 1) < argc && lst_sort[0][i] == lst_sort[0][i + 1])
			return (0);
		else if ((i + 1) < argc && lst_sort[0][i] > lst_sort[0][i + 1])
		{
			j = lst_sort[0][i + 1];
			lst_sort[0][i + 1] = lst_sort[0][i];
			lst_sort[0][i] = j;
			i = 0;
		}
		else
			i++;
	}
	return (1);
}

int	*nw_lst_order(t_num **col, int *lst_new, int len, int knob)
{
	int		*tmp;
	t_num	*tmp_col;
	int		i;

	tmp = malloc(sizeof(int) * len);
	if (!tmp)
		return (NULL);
	i = 0;
	if (*col)
	{
		tmp_col = *col;
		while (i < len)
		{
			tmp[i++] = tmp_col->nb;
			tmp_col = tmp_col->next;
		}
	}
	if (ft_order(&tmp, len) == 0)
	{
		free(tmp);
		return (NULL);
	}
	if (knob != 1)
		free(lst_new);
	return (tmp);
}
