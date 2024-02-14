/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundaries_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 20:16:16 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/12 23:21:23 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	has_wall_boundaries(char *line, int line_length)
{
	if (line[0] != '1' || line[line_length - 1] != '1')
		return (0);
	return (1);
}

int	is_all_walls(char *line)
{
	while (*(line))
	{
		if (*line != '1')
			return (0);
		line++;
	}
	return (1);
}

t_map	read_and_check_bonds(int fd)
{
	char	*line;
	t_map	map;

	line = get_next_line (fd);
	if (!line)
		no_data_in_file ();
	remove_nl (&line);
	if (!is_all_walls (line))
		invalid_map (line);
	map.weight = ft_strlen (line);
	map.height = 1;
	check_rest_of_lines (line, fd, &map.height, map.weight);
	return (map);
}
