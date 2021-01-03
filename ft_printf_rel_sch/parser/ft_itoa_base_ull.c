/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 10:36:43 by brice             #+#    #+#             */
/*   Updated: 2020/12/19 05:21:47 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
//#include "../libft/libft.h"

static	size_t	ft_size(unsigned long long int new, int base)
{
	int	sum;

	sum = 0;
	while (new / base)
	{
		new /= base;
		sum++;
	}
	sum++;
	return (sum);
}

static	char	*ft_while(char *str, unsigned int sum,
		unsigned long long int new, int base)
{
	while (sum > 2)
	{
		str[sum-- - 1] = new % base + (new % base > 9 ? 'W' : '0');
		new /= base;
	}
	return (str);
}

char			*ft_itoa_base_ull(unsigned long long int n, int base)
{
	char						*str;
	unsigned int				sum;
	unsigned long long int		new;

	new = n;
	sum = ft_size(new, base) + 2;
	if (!(str = ft_calloc(sizeof(char), (sum) + 2)))
		return (NULL);
	*(str + 0) = '0';
	*(str + 1) = 'x';
	str = ft_while(str, sum, new, base);
	return (str);
}
