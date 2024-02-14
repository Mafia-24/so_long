/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:17:16 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 15:05:05 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_enemy_right(t_vars *vars, int i)
{
	safe_put_image (vars, vars->game_images.bg_img,
		(vars->patrols[i].pos.y - 1) * 50, (vars->patrols[i].pos.x) * 50);
	reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y - 1);
	safe_put_image (vars, vars->game_images.bg_img,
		(vars->patrols[i].pos.y) * 50, (vars->patrols[i].pos.x) * 50);
	reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y);
	safe_put_image (vars,
		vars->game_images.r_enmy_imgs[vars->patrols[i].img_number],
		(vars->patrols[i].pos.y) * 50 + 12 * vars->patrols[i].img_number,
		(vars->patrols[i].pos.x) * 50);
	vars->patrols[i].img_number++;
	if (vars->patrols[i].img_number == 4)
	{
		vars->patrols[i].pos.y++;
		vars->patrols[i].img_number = 0;
	}
	if (vars->map.components[vars->patrols[i].pos.x][vars->patrols[i].pos.y + 1]
		== '1')
	{
		vars->patrols[i].direction = 'l';
		safe_put_image (vars, vars->game_images.bg_img,
			(vars->patrols[i].pos.y - 1) * 50, (vars->patrols[i].pos.x) * 50);
		reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y - 1);
	}
}

void	move_enemy_left(t_vars *vars, int i)
{
	safe_put_image (vars, vars->game_images.bg_img,
		(vars->patrols[i].pos.y + 1) * 50, (vars->patrols[i].pos.x) * 50);
	reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y + 1);
	safe_put_image (vars, vars->game_images.bg_img,
		(vars->patrols[i].pos.y) * 50, (vars->patrols[i].pos.x) * 50);
	reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y);
	safe_put_image (vars, vars->game_images.l_enmy_imgs[vars->patrols[i].img_number],
		(vars->patrols[i].pos.y) * 50 - 12 * vars->patrols[i].img_number,
		(vars->patrols[i].pos.x) * 50);
	vars->patrols[i].img_number++;
	if (vars->patrols[i].img_number == 4)
	{
		vars->patrols[i].pos.y--;
		vars->patrols[i].img_number = 0;
	}
	if (vars->map.components[vars->patrols[i].pos.x][vars->patrols[i].pos.y - 1]
	== '1')
	{
		vars->patrols[i].direction = 'r';
		safe_put_image (vars, vars->game_images.bg_img,
			(vars->patrols[i].pos.y + 1) * 50, (vars->patrols[i].pos.x) * 50);
		reset_image (vars, vars->patrols[i].pos.x, vars->patrols[i].pos.y + 1);
	}
}

void	move_enemie(t_vars *vars, int i)
{
	while (i < count_partolls(vars->map))
	{
		if (vars->patrols[i].direction == 'r')
		{
			move_enemy_right (vars, i);
			if (vars->patrols[i].pos.y == vars->player_pos.y
				&& vars->patrols[i].pos.x == vars->player_pos.x)
			{
				write (1, "u lost!\n", 8);
				exit_game (vars);
			}
		}
		else if (vars->patrols[i].direction == 'l')
		{
			move_enemy_left (vars, i);
			if (vars->patrols[i].pos.y == vars->player_pos.y
				&&vars->patrols[i].pos.x == vars->player_pos.x)
			{
				write (1, "u lost!\n", 8);
				exit_game (vars);
			}
		}
		i++;
	}
}
