/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymafaman <ymafaman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 01:12:39 by ymafaman          #+#    #+#             */
/*   Updated: 2024/02/14 16:27:09 by ymafaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	get_size(int n)
{
	long int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n / 10)
	{
		size++;
		n /= 10;
	}
	if (n % 10)
	{
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	subn;

	subn = n;
	res = (char *) malloc ((get_size(n) + 1));
	if (!res)
		return (NULL);
	i = get_size(n);
	*(res + i--) = '\0';
	res[0] = '0';
	if (subn < 0)
	{
		*res = '-';
		subn *= -1;
	}
	while (subn / 10)
	{
		*(res + i) = '0' + subn % 10;
		subn /= 10;
		i--;
	}
	if (subn % 10)
		*(res + i) = '0' + subn % 10;
	return (res);
}

char	*ft_strrchr(char *str, int c)
{
	int	l;

	l = ft_strlen(str);
	while (l > -1)
	{
		if ((unsigned char)str[l] == (unsigned char) c)
			return (&str[l]);
		l--;
	}
	return (NULL);
}
