/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 16:10:18 by ymafaman          #+#    #+#             */
/*   Updated: 2024/01/02 14:04:38 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_fill_full(char **st, char **fl)
{
	char	*new_st;
	char	*sub_st;
	int		i;

	i = 0;
	sub_st = *st;
	while (*sub_st)
	{
		(*fl)[i] = *sub_st;
		sub_st++;
		if ((*fl)[i] == '\n')
			break ;
		i++;
	}
	new_st = (char *)malloc((gnl_ft_strlen(sub_st, 1) + 1) * sizeof(char));
	if (!new_st)
		return (0);
	i = 0;
	while (*sub_st)
		*(new_st + i++) = *(sub_st++);
	*(new_st + i) = '\0';
	free(*st);
	*st = new_st;
	return (1);
}

int	fill_fl(char *buffer, int stop, char **fl)
{
	char	*temp;
	int		size;
	int		i;
	char	*sub_fl;

	i = 0;
	sub_fl = *fl;
	size = gnl_ft_strlen(*fl, 1) + stop + 2;
	if (buffer[stop] == '\0')
		size--;
	temp = (char *) malloc (size * sizeof(char));
	if (!temp)
		return (0);
	while (*sub_fl)
	{
		temp[i++] = *sub_fl;
		sub_fl++;
	}
	while (stop-- >= 0)
		temp[i++] = *(buffer++);
	temp[size - 1] = '\0';
	free(*fl);
	*fl = temp;
	return (1);
}

int	fill_st(char *buffer, int stop, char **st)
{
	char	*new_st;
	int		i;
	int		size;

	i = 0;
	if (stop == (int) gnl_ft_strlen(buffer, 1))
	{
		freeing(st, NULL, NULL, 1);
		return (1);
	}
	else
		size = gnl_ft_strlen(buffer, 1) - stop;
	new_st = (char *) malloc (size * sizeof(char));
	if (!new_st)
		return (0);
	while (++stop < (int) gnl_ft_strlen(buffer, 1))
		new_st[i++] = buffer[stop];
	new_st[i] = '\0';
	free(*st);
	*st = new_st;
	return (1);
}

int	cont_nl(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

size_t	gnl_ft_strlen(char *str, int type)
{
	int	len;

	len = 0;
	if (type == 1)
	{
		while (*str)
		{
			str++;
			len++;
		}
	}
	else
	{
		while (*str && *str != '\n')
		{
			str++;
			len++;
		}
		if (*str == '\n')
			len++;
	}
	return (len);
}
