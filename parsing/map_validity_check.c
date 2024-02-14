/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:03:13 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 16:25:17 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	valide_ber_file(char *file_name)
{
	int	i;

	if (ft_strrchr(file_name, '/')
		&& (ft_strrchr(file_name, '\0') - ft_strrchr(file_name, '/') - 1) <= 4)
		return (0);
	i = ft_strlen(file_name) - 4;
	if (!ft_strcmp (file_name + i, ".ber"))
		return (1);
	return (0);
}

int	check_components(char *line)
{
	while (*line)
	{
		if ((*line != '0') && (*line != '1') && (*line != 'P')
			&& (*line != 'C') && (*line != 'E') && (*line != 'G'))
		{
			return (0);
		}
		line++;
	}
	return (1);
}

void	read_and_store_map(t_map *map, int fd)
{
	int	i;

	map->components = (char **)malloc((map->height + 1) * sizeof(char *));
	if (!map->components)
		failed_allocation ();
	i = 0;
	while (i < map->height)
	{
		map->components[i] = get_next_line (fd);
		remove_nl (&map->components[i]);
		if (!check_components (map->components[i]))
		{
			while (i >= 0)
			{
				free (map->components[i]);
				i--;
			}
			free (map->components);
			invalid_component ();
		}
		i++;
	}
	map->components[i] = NULL;
	if (close (fd) == -1)
		failed_allocation ();
}

int	contain_necessary_components(t_map map, int i, int j)
{
	int	p_count;
	int	c_count;
	int	e_count;

	p_count = 0;
	c_count = 0;
	e_count = 0;
	while (map.components[i])
	{
		j = 0;
		while (map.components[i][j])
		{
			if (map.components[i][j] == 'P')
				p_count++;
			else if (map.components[i][j] == 'E')
				e_count++;
			else if (map.components[i][j] == 'C')
				c_count++;
			j++;
		}
		i++;
	}
	return ((p_count == 1) && (e_count == 1) && (c_count >= 1));
}

void	check_map(char *file_name)
{
	int		fd;
	t_map	map;

	if (!valide_ber_file(file_name))
		invalid_extension ();
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		cant_open_file (file_name);
	map = read_and_check_bonds (fd);
	close (fd);
	fd = open (file_name, O_RDONLY);
	if (fd == -1)
		cant_open_file (file_name);
	read_and_store_map (&map, fd);
	if (!contain_necessary_components (map, 0, 0))
	{
		free_2d (map.components);
		missing_components ();
	}
	if (!find_valid_path (map))
	{
		free_2d (map.components);
		absent_valid_path ();
	}
	initialize_map (map);
}
