/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:41:54 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:44:46 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

static	void	ft_print(t_cn *list, char *str)
{
	while (list->width > 0 && list->width > (int)ft_strlen(str))
	{
		list->bytes++;
		list->width--;
		write(1, " ", 1);
	}
}

void			ft_print_p(t_cn *list)
{
	char					*str;
	unsigned long long		num;

	num = va_arg(list->v_list, unsigned long long);
	if (!num && !list->accuracy && list->flag & FLAG_DOT)
		str = "0x";
	else
		str = ft_itoa_base_ull(num, 16);
	list->bytes += ft_strlen(str);
	if (list->width < 0)
	{
		list->width *= -1;
		list->flag |= FLAG_MINUS;
	}
	if ((list->flag & FLAG_MINUS))
	{
		write(1, &*str, ft_strlen(str));
		ft_print(list, str);
	}
	else
	{
		ft_print(list, str);
		write(1, &*str, ft_strlen(str));
	}
}
