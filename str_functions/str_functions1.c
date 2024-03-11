/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:15:04 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/15 21:38:35 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 > *s2)
			return (1);
		else if (*s1 < *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s1 && !(*s2))
		return (1);
	else if (!(*s1) && *s2)
		return (-1);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	unsigned int	len;
	char			*dup;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *) malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (0);
	while (i < len)
	{
		*(dup + i) = *(s1 + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}

void	ft_putnbr(int n)
{
	char	to_print;

	if (n == -2147483648)
		write (1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n *= -1;
		}
		if (n / 10)
		{
			to_print = '0' + n % 10;
			ft_putnbr(n / 10);
			write (1, &to_print, 1);
		}
		else
		{
			to_print = '0' + n % 10;
			write (1, &to_print, 1);
		}
	}
}
