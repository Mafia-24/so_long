/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:13:21 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/12 23:42:22 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	find_player_position(t_map map, t_point *player)
{
	int		i;
	int		j;

	i = 0;
	while (map.components[i])
	{
		j = 0;
		while (map.components[i][j])
		{
			if (map.components[i][j] == 'P')
			{
				player->x = i;
				player->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_portal_position(t_map map, t_point *player)
{
	int		i;
	int		j;

	i = 0;
	while (map.components[i])
	{
		j = 0;
		while (map.components[i][j])
		{
			if (map.components[i][j] == 'E')
			{
				player->x = i;
				player->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	find_dinau_position(t_map map, t_point *player)
{
	int		i;
	int		j;

	i = 0;
	while (map.components[i])
	{
		j = 0;
		while (map.components[i][j])
		{
			if (map.components[i][j] == 'G')
			{
				player->x = i;
				player->y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	can_pass_thrue(char c)
{
	if (c == '0' || c == 'E' || c == 'C' || c == 'G')
		return (1);
	return (0);
}
