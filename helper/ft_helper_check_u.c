/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_check_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:31:18 by brice             #+#    #+#             */
/*   Updated: 2021/01/12 19:03:55 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

void	ft_check_in_helper_u(int *base, int *flag)
{
	if (*base == 17)
	{
		*flag = 1;
		(*base)--;
	}
}

char	*ft_helper_check_u(t_cn *list, int *accuracy, int *flag, int *base)
{
	char	*str;

	*accuracy = list->accuracy;
	ft_check_in_helper_u(base, flag);
	if (!(str = ft_itoa_base_xu(va_arg(list->v_list, unsigned int), *base)))
	{
		list->bytes = -1;
		return (NULL);
	}
	if (*flag == 1)
	{
		*flag = 0;
		while (str[*flag])
		{
			str[*flag] = (char)ft_tolower(str[*flag]);
			(*flag)++;
		}
	}
	if (list->width < 0)
	{
		list->width *= -1;
		list->flag |= FLAG_MINUS;
	}
	return (str);
}
