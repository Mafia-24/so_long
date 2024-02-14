/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_game_play.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:30:42 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 17:36:44 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_images(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		vars->game_images.l_dino_imgs[i] = NULL;
		vars->game_images.r_dino_imgs[i] = NULL;
		vars->game_images.l_enmy_imgs[i] = NULL;
		vars->game_images.r_enmy_imgs[i] = NULL;
		i++;
	}
	vars->game_images.bg_img = NULL;
	vars->game_images.closed_exit = NULL;
	vars->game_images.open_exit = NULL;
	vars->game_images.coll_img = NULL;
	vars->game_images.wall_img = NULL;
}

t_vars	initialize_vars(t_map map, int i)
{
	t_vars	vars;

	i = 5;
	find_player_position (map, &vars.player_pos);
	vars.map = map;
	vars.mlx = mlx_init ();
	if (!vars.mlx)
	{
		free_2d (map.components);
		failed_allocation ();
	}
	vars.win = mlx_new_window (vars.mlx, map.weight * 50,
			map.height * 50, "./so_long");
	if (!vars.win)
	{
		free_2d (map.components);
		failed_allocation ();
	}
	vars.patrols = NULL;
	init_images (&vars);
	return (vars);
}

void	init_partrols(t_vars *vars, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.height)
	{
		j = 0;
		while (j < vars->map.weight)
		{
			if (vars->map.components[i][j] == 'G')
			{
				vars->patrols[count].pos.x = i;
				vars->patrols[count].pos.y = j;
				if (count % 2)
					vars->patrols[count].direction = 'l';
				else
					vars->patrols[count].direction = 'r';
				vars->patrols[count++].img_number = 0;
			}
			j++;
		}
		i++;
	}
}

void	set_party_infos(t_vars *vars)
{
	int	patrols_num;

	vars->party.movements = 0;
	vars->party.collected = 0;
	vars->party.player_direction = 'r';
	vars->party.total_colls = count_colls (vars->map);
	find_portal_position(vars->map, &vars->party.portal_pos);
	patrols_num = count_partolls(vars->map);
	if (patrols_num)
	{
		vars->patrols = (t_partrol *) malloc
			(patrols_num * sizeof (t_partrol));
		if (!vars->patrols)
		{
			free_allocated_vars (vars);
			failed_allocation ();
		}
		init_partrols(vars, 0);
	}
	else
		vars->patrols = NULL;
}



void	set_right_dino_imgs(t_vars *vars)
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
			vars->game_images.r_dino_imgs[i]= mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image4.xpm", &width, &height);
		if (!vars->game_images.r_dino_imgs[i])
		{
			free_allocated_vars (vars);
			failed_allocation ();
		}
		i++;
	}
}

void	set_left_dino_imgs(t_vars *vars)
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
			vars->game_images.l_dino_imgs[i]= mlx_xpm_file_to_image
				(vars->mlx, "./textures/dinosaur/image8.xpm", &width, &height);
		if (!vars->game_images.l_dino_imgs[i])
		{
			free_allocated_vars (vars);
			failed_allocation ();
		}
		i++;
	}
}

void	set_right_enemy_imgs(t_vars *vars)
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
		{
			free_allocated_vars (vars);
			failed_allocation ();
		}
		i++;
	}
}

void	set_left_enemy_imgs(t_vars *vars)
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
		{
			free_allocated_vars (vars);
			failed_allocation ();
		}
		i++;
	}
}

void	set_portal_imgs(t_vars *vars)
{
	int	width;
	int	height;

	vars->game_images.closed_exit = mlx_xpm_file_to_image (vars->mlx,
			"./textures/portal/portal1.xpm", &width, &height);
	if (!vars->game_images.closed_exit)
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
		(vars->mlx, "./textures/other_images/ground_test.xpm",&width, &height);
	if (!vars->game_images.bg_img)
	{
		free_allocated_vars (vars);
		failed_allocation ();
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

void	initialize_map(t_map map)
{
	t_vars	vars;
	char	*steps;

	vars = initialize_vars (map, 0);
	set_images (&vars);
	set_party_infos (&vars);
	map_to_image (map, &vars);
	if (mlx_string_put (vars.mlx, vars.win, 10, 10, 0x00FFFFFF, "Steps ") == -1)
		mlx_error(&vars);
	steps = ft_itoa (vars.party.movements);
	if (!steps)
	{
		free_allocated_vars (&vars);
		failed_allocation();
	}
	if (mlx_string_put (vars.mlx, vars.win, 70, 10, 0x00FFFFFF, steps) == -1)
		mlx_error(&vars);
	free (steps);
	if (mlx_key_hook(vars.win, &handle_keyrelease, &vars) == -1)
		mlx_error (&vars);
	if (mlx_hook(vars.win, 17, 1L << 17, exit_game, &vars) == -1)
		mlx_error (&vars);
	if (mlx_loop_hook(vars.mlx, &move_enemies, &vars) == -1)
		mlx_error (&vars);
	if (mlx_loop(vars.mlx) == -1)
		mlx_error (&vars);
}
