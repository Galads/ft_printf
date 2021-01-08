/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helpers_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:00:51 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:21:16 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

void	ft_print_helper(t_cn *list, char **str, int *i)
{
	write(1, &(*str)[(*i)++], 1);
	list->bytes++;
}

void	ft_print_second_helper(t_cn *list)
{
	list->width--;
	list->bytes++;
	write(1, " ", 1);
}
