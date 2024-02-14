/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:30:56 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/12 23:04:48 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_partolls(t_map map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.weight)
		{
			if (map.components[i][j] == 'G')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_colls(t_map map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.weight)
		{
			if (map.components[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
