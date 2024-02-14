/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:08:41 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/02 14:04:44 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*freeing(char **st, char **buffer, char **fl, int type)
{
	if (type == 1 || type == 10)
	{
		free(*st);
		*st = NULL;
	}
	if (type == 2 || type == 10)
	{
		free(*fl);
		free(*buffer);
		*fl = NULL;
		*buffer = NULL;
	}
	else if (type == 3)
	{
		free(*buffer);
		*buffer = NULL;
	}
	else if (type == 4)
	{
		free(*fl);
		*fl = NULL;
	}
	return (NULL);
}

int	reader(int fd, char **buffer, char **fl, char **stat)
{
	int	i;
	int	reed;

	i = 0;
	reed = read(fd, *buffer, BUFFER_SIZE);
	if (!reed)
		return (-1);
	(*buffer)[reed] = '\0';
	while (i < reed)
	{
		if ((*buffer)[i] == '\n')
			break ;
		i++;
	}
	if (!fill_fl(*buffer, i, fl) || !fill_st(*buffer, i, stat))
	{
		freeing(stat, buffer, fl, 10);
		return (0);
	}
	return (1);
}

int	allocating(char **buffer, char **fl, char **st)
{
	size_t	size;

	*buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!(*buffer))
		return (0);
	if (*st)
		size = gnl_ft_strlen(*st, 2) + 1;
	else
		size = 1;
	*fl = (char *)malloc(size * sizeof(char));
	if (!(*fl))
	{
		freeing(NULL, buffer, NULL, 3);
		return (0);
	}
	if (*st && !init_fill_full(st, fl))
	{
		freeing(NULL, buffer, fl, 2);
		return (0);
	}
	(*fl)[size - 1] = '\0';
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*st;
	char		*buffer;
	char		*fl;
	int			rett;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, "", 0) < 0
		|| !allocating(&buffer, &fl, &st))
		return (freeing(&st, NULL, NULL, 1));
	while (!cont_nl(fl))
	{
		rett = reader(fd, &buffer, &fl, &st);
		if (!rett)
			return (NULL);
		else if (rett == -1)
		{
			freeing(&st, NULL, NULL, 1);
			break ;
		}
	}
	freeing(NULL, &buffer, NULL, 3);
	if (!gnl_ft_strlen(fl, 1))
		return (freeing(NULL, NULL, &fl, 4));
	return (fl);
}
