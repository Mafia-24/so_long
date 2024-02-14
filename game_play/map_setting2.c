/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:57 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 17:29:34 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_background_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window(vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
}

void	map_to_image(t_map map, t_vars *vars)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.height)
	{
		j = 0;
		while (j < map.weight)
		{
			if (map.components[i][j] == 'P')
				set_dinosor_image (vars, i, j);
			else if (map.components[i][j] == 'C')
				set_collectible_image (vars, i, j);
			else if (map.components[i][j] == 'G')
				set_patrol_image (vars, i, j);
			else if (map.components[i][j] == '1')
				set_wall_image (vars, i, j);
			else if (map.components[i][j] == 'E')
				set_exit_image (vars, i, j);
			else
				set_background_image (vars, i, j);
			j++;
		}
		i++;
	}
}
