/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_minus_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:37:33 by brice             #+#    #+#             */
/*   Updated: 2021/01/11 16:29:35 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_helper.h"

void	ft_check_minus_helper(t_cn *list, char **str, int *accuracy)
{
	if (**str == '-' && (list->flag & FLAG_MINUS))
	{
		list->width--;
		(*str)++;
		write(1, "-", 1);
		list->bytes++;
		ft_while_print_null_helper(list, str);
	}
	ft_while_print_null_helper(list, str);
	if (**str == '0' && list->flag & FLAG_DOT && !*accuracy)
		write(1, " ", (int)ft_strlen(*str));
	else
		write(1, *str, (int)ft_strlen(*str));
	list->bytes += (int)ft_strlen(*str);
}
