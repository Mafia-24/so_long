/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moving.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 22:17:15 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/15 22:34:29 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player_up(t_vars *vars, int x, int y)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (vars->map.components[x - 1][y] != '1')
	{
		if (vars->map.components[x - 1][y] == 'E' &&
			vars->party.collected == vars->party.total_colls)
		{
			write (1, "U won!\n", 8);
			exit_game (vars);
		}
		change_images_up(vars, i++);
		if (vars->map.components[x - 1][y] == 'C')
		{
			vars->map.components[x - 1][y] = 'c';
			vars->party.collected++;
		}
		vars->player_pos.x = vars->player_pos.x - 1;
		vars->party.movements++;
		put_steps_number (vars);
	}
}

void	move_player_down(t_vars *vars, int x, int y)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (vars->map.components[x + 1][y] != '1')
	{
		if (vars->map.components[x + 1][y] == 'E'
			&& vars->party.collected == vars->party.total_colls)
		{
			write (1, "U won!\n", 8);
			exit_game (vars);
		}
		change_images_down(vars, i++);
		if (vars->map.components[x + 1][y] == 'C')
		{
			vars->map.components[x + 1][y] = 'c';
			vars->party.collected++;
		}
		vars->player_pos.x = vars->player_pos.x + 1;
		vars->party.movements++;
		put_steps_number (vars);
	}
}

void	move_player_right(t_vars *vars, int x, int y)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (vars->map.components[x][y + 1] != '1')
	{
		if (vars->map.components[x][y + 1] == 'E'
			&& vars->party.collected == vars->party.total_colls)
		{
			write (1, "U won!\n", 8);
			exit_game (vars);
		}
		vars->party.player_direction = 'r';
		change_images_right(vars, i++);
		if (vars->map.components[x][y + 1] == 'C')
		{
			vars->map.components[x][y + 1] = 'c';
			vars->party.collected++;
		}
		vars->player_pos.y = vars->player_pos.y + 1;
		put_steps_number (vars);
	}
}

void	move_player_left(t_vars *vars, int x, int y)
{
	static int	i;

	if (i == 4)
		i = 0;
	if (vars->map.components[x][y - 1] != '1')
	{
		if (vars->map.components[x][y - 1] == 'E'
			&& vars->party.collected == vars->party.total_colls)
		{
			write (1, "U won!\n", 8);
			exit_game (vars);
		}
		vars->party.player_direction = 'l';
		change_images_left(vars, i++);
		if (vars->map.components[x][y - 1] == 'C')
		{
			vars->map.components[x][y - 1] = 'c';
			vars->party.collected++;
		}
		vars->player_pos.y = vars->player_pos.y - 1;
		put_steps_number (vars);
	}
}
