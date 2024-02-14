/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:07:14 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 17:35:01 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	invalid_extension(void)
{
	write (2, "Error\n", 6);
	write (2, "Invalid file extension!\n", 24);
	exit (1);
}

void	cant_open_file(char *file_name)
{
	write (2, "Error\n", 6);
	write (2, "The file (", 10);
	write (2, file_name, ft_strlen(file_name));
	write (2, ") can't be opened! Check the file name or permissions!\n", 55);
	exit (1);
}

void	no_data_in_file(void)
{
	write (2, "Error\n", 6);
	write (2, "The file contain no data!\n", 26);
	exit (1);
}

void	invalid_map(char *line)
{
	free (line);
	write (2, "Error\n", 6);
	write (2, "The provided map is invalid!\n", 29);
	exit (1);
}

void	failed_allocation(void)
{
	write (2, "An allocation has failed! The program will exit.\n", 49);
	exit (1);
}
