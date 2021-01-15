/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:41:54 by brice             #+#    #+#             */
/*   Updated: 2021/01/12 19:19:54 by brice            ###   ########.fr       */
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

static	void	ft_check_fst(t_cn *list, char **str)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->flag |= FLAG_MINUS;
	}
	if ((list->flag & FLAG_MINUS))
	{
		write(1, *str, (int)ft_strlen(*str));
		ft_print(list, *str);
	}
	else
	{
		ft_print(list, *str);
		write(1, *str, (int)ft_strlen(*str));
	}
}

void			ft_print_p(t_cn *list)
{
	char					*str;
	char					*save;
	unsigned long long		num;

	num = va_arg(list->v_list, unsigned long long);
	if (!num && !list->accuracy && list->flag & FLAG_DOT)
		str = "0x";
	else
	{
		if (!(str = ft_itoa_base_ull(num, 16)))
		{
			list->bytes = -1;
			return ;
		}
	}
	save = str;
	list->bytes += (int)ft_strlen(str);
	ft_check_fst(list, &str);
	if (save[0] == '0' && save[1] == 'x' && (int)ft_strlen(save) == 2)
		return ;
	if (save != NULL)
		free(save);
}
