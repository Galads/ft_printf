/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_while_print_null_helper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:44:56 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:21:56 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

void	ft_while_print_null_helper(t_cn *list, char **str)
{
	while (list->accuracy > (int)ft_strlen(*str) && list->accuracy > 0)
	{
		write(1, "0", 1);
		list->accuracy--;
		list->bytes++;
		list->width--;
	}
}
