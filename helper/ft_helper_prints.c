/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:00:41 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:20:38 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

void	ft_print_in(t_cn *list)
{
	write(1, "0", 1);
	list->accuracy--;
	list->bytes++;
}

void	ft_helper_print(t_cn *list, char **str, int *accuracy, int *flag)
{
	if (*flag == 1 && !(list->flag & FLAG_NULL))
		write(1, "-", 1);
	if (list->flag & FLAG_DOT && *accuracy > 0)
	{
		if (**str == '-' && list->accuracy > (int)ft_strlen(*str) &&
												list->accuracy > list->width)
		{
			(*str)++;
			write(1, "-", 1);
		}
		while (list->accuracy > (int)ft_strlen(*str))
			ft_print_in(list);
	}
	else
	{
		while (list->width - (int)ft_strlen(*str) > 0)
			ft_print_in(list);
	}
}

void	ft_helper_print_second(t_cn *list, char **str, int *accuracy)
{
	if (**str == '0' && (int)ft_strlen(*str) == 1 &&
									list->flag & FLAG_DOT && list->width)
	{
		if ((list->flag & FLAG_DOT) && *accuracy)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	else if (**str == '0' && !*accuracy && list->flag & FLAG_DOT)
		list->bytes--;
	else
	{
		if (**str == '-' && *accuracy == (int)ft_strlen(*str))
		{
			(*str)++;
			write(1, "-0", 2);
		}
		else if (**str == '-' && list->width < *accuracy)
		{
			(*str)++;
			list->bytes++;
			write(1, "0", 1);
		}
		write(1, *str, (int)ft_strlen(*str));
	}
}
