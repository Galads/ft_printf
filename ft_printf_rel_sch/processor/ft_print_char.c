/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:20:09 by brice             #+#    #+#             */
/*   Updated: 2020/12/19 05:26:38 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_print(s_cn *list)
{
	if (list->width)
	{
		if (list->width != 0)
		{
			while (--list->width)
			{
				list->bytes++;
				write(1, " ", 1);
			}
		}
	}
}

void	ft_print_char(s_cn *list)
{
	char chr;

	chr = va_arg(list->v_list, int);
	if (list->width < 0)
	{
		list->width *= -1;
		list->flag |= FLAG_MINUS;
	}
	if (list->flag & FLAG_MINUS)
	{
		write(1, &chr, 1);
		ft_print(list);
	}
	else
	{
		ft_print(list);
		write(1, &chr, 1);
	}
	list->bytes++;
}
