/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:51:38 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:18:25 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reset_image(t_vars *vars, int x, int y)
{
	if (vars->map.components[x][y] == 'C')
		safe_put_image (vars, vars->game_images.coll_img, y * 50, x * 50);
	else if (vars->map.components[x][y] == 'E')
	{
		if (vars->party.collected == vars->party.total_colls)
			safe_put_image (vars, vars->game_images.open_exit, y * 50, x * 50);
		else
			safe_put_image (vars, vars->game_images.cld_exit, y * 50, x * 50);
	}
	else if (x == vars->player_pos.x && y == vars->player_pos.y)
	{
		if (vars->party.player_direction == 'r')
		{
			if (mlx_put_image_to_window (vars->mlx, vars->win,
					vars->game_images.r_dino_imgs[1], y * 50, x * 50) == -1)
				mlx_error (vars);
		}
		else
			if (mlx_put_image_to_window (vars->mlx, vars->win,
					vars->game_images.l_dino_imgs[1], y * 50, x * 50) == -1)
				mlx_error (vars);
	}
	else if (vars->map.components[x][y] == '1')
		safe_put_image (vars, vars->game_images.wall_img, y * 50, x * 50);
	return ;
}

void	check_portal(t_vars *vars)
{
	static bool	opened;

	if (vars->party.collected == vars->party.total_colls && !opened)
	{
		if (mlx_put_image_to_window(vars->mlx, vars->win,
				vars->game_images.bg_img, vars->party.portal_pos.y * 50,
				vars->party.portal_pos.x * 50) == -1)
			mlx_error (vars);
		if (mlx_put_image_to_window(vars->mlx, vars->win,
				vars->game_images.open_exit, vars->party.portal_pos.y * 50,
				vars->party.portal_pos.x * 50) == -1)
			mlx_error (vars);
		opened = true;
	}
}

int	move_enemies(t_vars *vars)
{
	static int	frame;

	check_portal (vars);
	if (frame == 1350)
	{
		move_enemie(vars, 0);
		frame = 0;
	}
	else
		frame++;
	return (1);
}
