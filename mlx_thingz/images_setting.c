/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 18:23:51 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:36:45 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	set_right_dino_imgs(t_vars *vars)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			vars->game_images.r_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image1.xpm", &width, &height);
		else if (i == 1)
			vars->game_images.r_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image2.xpm", &width, &height);
		else if (i == 2)
			vars->game_images.r_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image3.xpm", &width, &height);
		else
			vars->game_images.r_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image4.xpm", &width, &height);
		if (!vars->game_images.r_dino_imgs[i])
			return (free_allocated_vars (vars), failed_allocation());
		i++;
	}
}

static void	set_left_dino_imgs(t_vars *vars)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			vars->game_images.l_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image5.xpm", &width, &height);
		else if (i == 1)
			vars->game_images.l_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image6.xpm", &width, &height);
		else if (i == 2)
			vars->game_images.l_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image7.xpm", &width, &height);
		else
			vars->game_images.l_dino_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image8.xpm", &width, &height);
		if (!vars->game_images.l_dino_imgs[i])
			return (free_allocated_vars (vars), failed_allocation());
		i++;
	}
}

static void	set_right_enemy_imgs(t_vars *vars)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			vars->game_images.r_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image1.xpm", &width, &height);
		else if (i == 1)
			vars->game_images.r_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image2.xpm", &width, &height);
		else if (i == 2)
			vars->game_images.r_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image3.xpm", &width, &height);
		else if (i == 3)
			vars->game_images.r_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image4.xpm", &width, &height);
		if (!vars->game_images.r_enmy_imgs[i])
			return (free_allocated_vars (vars), failed_allocation());
		i++;
	}
}

static void	set_left_enemy_imgs(t_vars *vars)
{
	int		width;
	int		height;
	int		i;

	i = 0;
	while (i < 4)
	{
		if (i == 0)
			vars->game_images.l_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image5.xpm", &width, &height);
		else if (i == 1)
			vars->game_images.l_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image6.xpm", &width, &height);
		else if (i == 2)
			vars->game_images.l_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image7.xpm", &width, &height);
		else if (i == 3)
			vars->game_images.l_enmy_imgs[i] = mlx_xpm_file_to_image
				(vars->mlx, "./textures/player/image8.xpm", &width, &height);
		if (!vars->game_images.r_enmy_imgs[i])
			return (free_allocated_vars (vars), failed_allocation());
		i++;
	}
}

void	set_images(t_vars *vars)
{
	set_right_dino_imgs (vars);
	set_left_dino_imgs (vars);
	set_right_enemy_imgs (vars);
	set_left_enemy_imgs (vars);
	set_portal_imgs (vars);
	set_other_images (vars);
}
