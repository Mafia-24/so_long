/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path_checking_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:25:20 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/11 08:54:16 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	colorise(t_map map, int x, int y)
{
	if (map.components[x][y] == '0')
		map.components[x][y] = '.';
	else
		map.components[x][y] += 32;
}

int	check_colored_map(t_map sub_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (sub_map.components[i])
	{
		j = 0;
		while (sub_map.components[i][j])
		{
			if (sub_map.components[i][j] == 'C'
				|| sub_map.components[i][j] == 'E')
				return (free_2d (sub_map.components), 0);
			j++;
		}
		i++;
	}
	return (free_2d (sub_map.components), 1);
}

void	flood_fill(t_map map, t_point pos)
{
	if (can_pass_thrue(map.components[pos.x + 1][pos.y]))
	{
		colorise (map, pos.x + 1, pos.y);
		flood_fill (map, (t_point){.x = pos.x + 1, .y = pos.y});
	}
	if (can_pass_thrue(map.components[pos.x - 1][pos.y]))
	{
		colorise (map, pos.x - 1, pos.y);
		flood_fill (map, (t_point){.x = pos.x - 1, .y = pos.y});
	}
	if (can_pass_thrue(map.components[pos.x][pos.y + 1]))
	{
		colorise (map, pos.x, pos.y + 1);
		flood_fill (map, (t_point){.x = pos.x, .y = pos.y + 1});
	}
	if (can_pass_thrue(map.components[pos.x][pos.y - 1]))
	{
		colorise (map, pos.x, pos.y - 1);
		flood_fill (map, (t_point){.x = pos.x, .y = pos.y - 1});
	}
}

int	find_valid_path(t_map map)
{
	t_point	pos;
	t_map	sub_map;
	int		i;

	i = 0;
	sub_map.components = (char **) malloc ((map.height + 1) * sizeof(char *));
	while (i < map.height)
	{
		sub_map.components[i] = ft_strdup (map.components[i]);
		if (!sub_map.components[i])
			failed_allocation ();
		i++;
	}
	sub_map.components[i] = NULL;
	find_player_position (sub_map, &pos);
	flood_fill (sub_map, pos);
	return (check_colored_map (sub_map));
}
