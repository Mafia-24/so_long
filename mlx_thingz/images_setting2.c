/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_setting2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:27:18 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:36:30 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	set_portal_imgs(t_vars *vars)
{
	int	width;
	int	height;

	vars->game_images.cld_exit = mlx_xpm_file_to_image (vars->mlx,
			"./textures/portal/portal1.xpm", &width, &height);
	if (!vars->game_images.cld_exit)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
	vars->game_images.open_exit = mlx_xpm_file_to_image(vars->mlx,
			"./textures/portal/portal4.xpm", &width, &height);
	if (!vars->game_images.open_exit)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
}

void	set_other_images(t_vars *vars)
{
	int	width;
	int	height;

	vars->game_images.coll_img = mlx_xpm_file_to_image (vars->mlx,
			"./textures/collectible/collectible.xpm", &width, &height);
	if (!vars->game_images.coll_img)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
	vars->game_images.wall_img = mlx_xpm_file_to_image (vars->mlx,
			"./textures/other_images/wall_test.xpm", &width, &height);
	if (!vars->game_images.wall_img)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
	vars->game_images.bg_img = mlx_xpm_file_to_image
		(vars->mlx, "./textures/other_images/ground_test.xpm", &width, &height);
	if (!vars->game_images.bg_img)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
}
