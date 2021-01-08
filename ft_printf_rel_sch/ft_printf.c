/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 18:30:58 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:13:25 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_printf.h"

int		ft_printf(char *format, ...)
{
	t_cn	conv;
	int		ret;

	va_start(conv.v_list, format);
	ret = ft_parser(format, &conv);
	va_end(conv.v_list);
	return (ret);
}
