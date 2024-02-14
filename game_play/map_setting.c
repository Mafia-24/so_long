/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:35:14 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:17:20 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_patrol_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.r_enmy_imgs[0], 50 * j, 50 * i) == -1)
		mlx_error (vars);
}

void	set_collectible_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.coll_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
}

void	set_dinosor_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.r_dino_imgs[0], 50 * j, 50 * i) == -1)
		mlx_error (vars);
}

void	set_wall_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.wall_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
}

void	set_exit_image(t_vars *vars, int i, int j)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.bg_img, 50 * j, 50 * i) == -1)
		mlx_error (vars);
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			vars->game_images.cld_exit, 50 * j, 50 * i) == -1)
		mlx_error (vars);
}
