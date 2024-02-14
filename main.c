/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:29:47 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 15:39:28 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	if (ac != 2)
	{
		write (2, "Error\n", 6);
		write (2, "Invalid number of arguments!\n", 29);
		exit (1);
	}
	check_map(av[1]);
	return (0);
}
