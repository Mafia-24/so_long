/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 04:12:08 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 18:29:08 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	safe_put_image(t_vars *vars, void *img, int i, int j)
{
	if (mlx_put_image_to_window
		(vars->mlx, vars->win, img, i, j) == -1)
		mlx_error(vars);
}

void	put_steps_number(t_vars *vars)
{
	char	*steps;

	safe_put_image (vars, vars->game_images.bg_img, 0, 0);
	safe_put_image (vars, vars->game_images.wall_img, 0, 0);
	safe_put_image (vars, vars->game_images.bg_img, 50, 0);
	safe_put_image (vars, vars->game_images.wall_img, 50, 0);
	safe_put_image (vars, vars->game_images.bg_img, 100, 0);
	safe_put_image (vars, vars->game_images.wall_img, 100, 0);
	if (mlx_string_put (vars->mlx, vars->win, 10, 10,
			0x00FFFFFF, "Steps ") == -1)
		mlx_error (vars);
	steps = ft_itoa (vars->party.movements);
	if (!steps)
	{
		free_allocated_vars (vars);
		failed_allocation ();
	}
	if (mlx_string_put (vars->mlx, vars->win, 70, 10, 0x00FFFFFF, steps) == -1)
	{
		free (steps);
		mlx_error (vars);
	}
	free (steps);
}

int	handle_keyrelease(int keysym, t_vars *vars)
{
	if (keysym == 53)
		exit_game (vars);
	else if (keysym == 13)
	{
		move_player_up (vars);
	}
	else if (keysym == 2)
	{
		move_player_right (vars);
	}
	else if (keysym == 1)
	{
		move_player_down (vars);
	}
	if (keysym == 0)
	{
		move_player_left (vars);
	}
	put_steps_number (vars);
	return (0);
}

int	exit_game(t_vars *vars)
{
	exit_free (vars);
	return (exit (0), 0);
}
