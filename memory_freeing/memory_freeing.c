/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_freeing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:03:08 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 17:37:43 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free (arr[i]);
		i++;
	}
	free (arr);
}

void	exit_free(t_vars *vars)
{
	int	i;

	i = 0;
	free_2d (vars->map.components);
	free (vars->patrols);
	while (i < 4)
	{
		mlx_destroy_image (vars->mlx, vars->game_images.r_dino_imgs[i]);
		mlx_destroy_image (vars->mlx, vars->game_images.l_dino_imgs[i]);
		mlx_destroy_image (vars->mlx, vars->game_images.l_enmy_imgs[i]);
		mlx_destroy_image (vars->mlx, vars->game_images.r_enmy_imgs[i]);
		i++;
	}
	mlx_destroy_image (vars->mlx, vars->game_images.bg_img);
	mlx_destroy_image (vars->mlx, vars->game_images.closed_exit);
	mlx_destroy_image (vars->mlx, vars->game_images.coll_img);
	mlx_destroy_image (vars->mlx, vars->game_images.open_exit);
	mlx_destroy_image (vars->mlx, vars->game_images.wall_img);
	mlx_destroy_window (vars->mlx, vars->win);
}

static void	free_rest_vars(t_vars *vars)
{
	if (vars->game_images.closed_exit)
		mlx_destroy_image (vars->mlx, vars->game_images.closed_exit);
	if (vars->game_images.open_exit)
		mlx_destroy_image (vars->mlx, vars->game_images.open_exit);
	if (vars->game_images.coll_img)
		mlx_destroy_image (vars->mlx, vars->game_images.coll_img);
	if (vars->game_images.wall_img)
		mlx_destroy_image (vars->mlx, vars->game_images.wall_img);
	if (vars->game_images.bg_img)
		mlx_destroy_image (vars->mlx, vars->game_images.bg_img);
	free_2d (vars->map.components);
	if (vars->patrols)
		free (vars->patrols);
	mlx_destroy_window (vars->mlx, vars->win);
}

void	free_allocated_vars(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!vars->game_images.r_dino_imgs[i])
			break;
		mlx_destroy_image (vars->mlx, vars->game_images.r_dino_imgs[i]);
		if (!vars->game_images.l_dino_imgs[i])
			break;
		mlx_destroy_image (vars->mlx, vars->game_images.l_dino_imgs[i]);
		if (!vars->game_images.r_enmy_imgs[i])
			break;
		mlx_destroy_image (vars->mlx, vars->game_images.r_enmy_imgs[i]);
		if (!vars->game_images.l_enmy_imgs[i])
			break;
		mlx_destroy_image (vars->mlx, vars->game_images.l_enmy_imgs[i]);
		i++;
	}
	if (i == 4)
	{
		free_rest_vars (vars);
	}
}
