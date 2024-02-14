/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:21:01 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 17:35:22 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_component(void)
{
	write (2, "Error\n", 6);
	write (2, "The map contain an invalid component!\n", 38);
	exit (1);
}

void	absent_valid_path(void)
{
	write (2, "Error\n", 6);
	write (2, "The map does not contain a valid path!\n", 39);
	exit (1);
}

void	missing_components(void)
{
	write (2, "Error\n", 6);
	write (2, "The map does not contain all necessary components!\n", 51);
	exit (1);
}

void	mlx_error(t_vars *vars)
{
	write (2, "MLX error!\n", 11);
	exit_free (vars);
	exit (1);
}
