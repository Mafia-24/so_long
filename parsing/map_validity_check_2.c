/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_check_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:35:26 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/12 23:22:50 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	remove_nl(char **line)
{
	int		i;
	char	*new_line;

	i = 0;
	new_line = NULL;
	while ((*line)[i])
		i++;
	if ((*line)[i - 1] == '\n')
	{
		i--;
		new_line = (char *) malloc ((i + 1) * sizeof (char));
		if (!new_line)
			failed_allocation ();
		new_line[i] = '\0';
		i--;
		while (i >= 0)
		{
			new_line[i] = (*line)[i];
			i--;
		}
		free (*line);
		*line = new_line;
	}
}

void	check_rest_of_lines(char *line, int fd, int *lines_num, int line_length)
{
	char	*last_line;

	last_line = NULL;
	while (1)
	{
		free (last_line);
		last_line = ft_strdup (line);
		if (!last_line)
			failed_allocation ();
		free (line);
		line = get_next_line (fd);
		if (!line)
			break ;
		remove_nl (&line);
		if ((ft_strlen (line) != line_length)
			|| !has_wall_boundaries (line, line_length))
		{
			free (last_line);
			invalid_map (line);
		}
		(*lines_num)++;
	}
	if (!is_all_walls (last_line))
		invalid_map (last_line);
	free (last_line);
}
