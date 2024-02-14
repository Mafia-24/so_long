/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changing_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:33:53 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:37:25 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	short_put_img_to_window(t_vars *vars, int x, int y, void *img)
{
	if (mlx_put_image_to_window (vars->mlx, vars->win,
			img, 50 * y, 50 * x) == -1)
		mlx_error (vars);
}

void	change_images_up(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = vars->player_pos.x;
	y = vars->player_pos.y;
	short_put_img_to_window (vars, x, y, vars->game_images.bg_img);
	if (vars->map.components[x][y] == 'E')
		short_put_img_to_window (vars, x, y, vars->game_images.cld_exit);
	short_put_img_to_window (vars, x - 1, y, vars->game_images.bg_img);
	if (vars->map.components[x - 1][y] == 'E')
		short_put_img_to_window (vars, x - 1, y, vars->game_images.cld_exit);
	if (vars->party.player_direction == 'r')
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.r_dino_imgs[i], y * 50, (x - 1) * 50) == -1)
			mlx_error (vars);
	}
	else
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.l_dino_imgs[i], y * 50, (x - 1) * 50) == -1)
			mlx_error (vars);
	}
}

void	change_images_down(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = vars->player_pos.x;
	y = vars->player_pos.y;
	short_put_img_to_window (vars, x, y, vars->game_images.bg_img);
	if (vars->map.components[x][y] == 'E')
		short_put_img_to_window (vars, x, y, vars->game_images.cld_exit);
	short_put_img_to_window (vars, x + 1, y, vars->game_images.bg_img);
	if (vars->map.components[x + 1][y] == 'E')
		short_put_img_to_window (vars, x + 1, y, vars->game_images.cld_exit);
	if (vars->party.player_direction == 'r')
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.r_dino_imgs[i], y * 50, (x + 1) * 50) == -1)
			mlx_error (vars);
	}
	else
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.l_dino_imgs[i], y * 50, (x + 1) * 50) == -1)
			mlx_error (vars);
	}
}

void	change_images_right(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = vars->player_pos.x;
	y = vars->player_pos.y;
	vars->party.movements++;
	short_put_img_to_window (vars, x, y, vars->game_images.bg_img);
	if (vars->map.components[x][y] == 'E')
		short_put_img_to_window (vars, x, y, vars->game_images.cld_exit);
	short_put_img_to_window (vars, x, y + 1, vars->game_images.bg_img);
	if (vars->map.components[x][y + 1] == 'E')
		short_put_img_to_window (vars, x, y + 1, vars->game_images.cld_exit);
	if (vars->party.player_direction == 'r')
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.r_dino_imgs[i], (y + 1) * 50, x * 50) == -1)
			mlx_error (vars);
	}
	else
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.l_dino_imgs[i], (y + 1) * 50, x * 50) == -1)
			mlx_error (vars);
	}
}

void	change_images_left(t_vars *vars, int i)
{
	int	x;
	int	y;

	x = vars->player_pos.x;
	y = vars->player_pos.y;
	vars->party.movements++;
	short_put_img_to_window (vars, x, y, vars->game_images.bg_img);
	if (vars->map.components[x][y] == 'E')
		short_put_img_to_window (vars, x, y, vars->game_images.cld_exit);
	short_put_img_to_window (vars, x, y - 1, vars->game_images.bg_img);
	if (vars->map.components[x][y - 1] == 'E')
		short_put_img_to_window (vars, x, y - 1, vars->game_images.cld_exit);
	if (vars->party.player_direction == 'r')
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.r_dino_imgs[i], (y - 1) * 50, x * 50) == -1)
			mlx_error (vars);
	}
	else
	{
		if (mlx_put_image_to_window (vars->mlx, vars->win,
				vars->game_images.l_dino_imgs[i], (y - 1) * 50, x * 50) == -1)
			mlx_error (vars);
	}
}
