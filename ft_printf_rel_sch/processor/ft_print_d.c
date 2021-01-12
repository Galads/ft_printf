/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:25:50 by brice             #+#    #+#             */
/*   Updated: 2021/01/12 17:57:19 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"
#include "ft_helper.h"

static	void	ft_loop(t_cn *list, char **str)
{
	while (list->accuracy > (int)ft_strlen(*str) && list->accuracy > 0)
	{
		write(1, "0", 1);
		list->accuracy--;
		list->bytes++;
		list->width--;
	}
}

static	void	flag_minus(t_cn *list, char **str)
{
	if (**str == '-' && (list->flag & FLAG_MINUS))
	{
		list->width--;
		(*str)++;
		write(1, "-", 1);
		list->bytes++;
		ft_loop(list, str);
	}
	ft_loop(list, str);
	if (**str == '0' && (list->flag & FLAG_DOT) && list->accuracy == 0)
		write(1, " ", 1);
	else
		write(1, *str, (int)ft_strlen(*str));
	list->bytes += (int)ft_strlen(*str);
	while (list->width - list->accuracy > 0 &&
											list->width > (int)ft_strlen(*str))
	{
		list->bytes++;
		list->width--;
		write(1, " ", 1);
	}
}

static	void	flag_plus(t_cn *list, char **str, int *accuracy, int *flag)
{
	*accuracy = list->accuracy;
	if (*accuracy < 0)
		list->accuracy *= -1;
	*flag = 0;
	list->bytes += (int)ft_strlen(*str);
	if (**str == '-' && !(list->flag & FLAG_MINUS) && !(list->flag & FLAG_NULL))
	{
		list->width--;
		(*str)++;
		*flag = 1;
	}
	else if (**str == '-' && list->flag & FLAG_NULL
								&& !list->accuracy && !(list->flag & FLAG_DOT))
	{
		list->width--;
		(*str)++;
		write(1, "-", 1);
	}
}

static	void	flag_minus_loop(t_cn *list, char **str, int *accuracy)
{
	while (list->width - list->accuracy > 0 &&
										list->width > (int)ft_strlen(*str))
	{
		list->bytes++;
		list->width--;
		if (**str == '-' && list->width == list->accuracy &&
				list->accuracy > 0 && list->accuracy > (int)ft_strlen(*str))
		{
			(*str)++;
			list->bytes--;
			write(1, "-", 1);
			continue;
		}
		if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT))
				|| *accuracy < 0)
		{
			write(1, "0", 1);
			continue;
		}
		if (**str == '-' && list->accuracy == (int)ft_strlen(*str) &&
												list->width == list->accuracy)
			break ;
		write(1, " ", 1);
	}
}

void			ft_print_d(t_cn *list)
{
	char	*str;
	char	*save;
	int		accuracy;
	int		flag;

	if (!(str = ft_itoa(va_arg(list->v_list, int))))
	{
		list->bytes = -1;
		return ;
	}
	save = str;
	ft_first_check_d_help(list);
	if ((list->flag & FLAG_MINUS))
		flag_minus(list, &str);
	else
	{
		flag_plus(list, &str, &accuracy, &flag);
		flag_minus_loop(list, &str, &accuracy);
		ft_helper_print(list, &str, &accuracy, &flag);
		ft_helper_print_second(list, &str, &accuracy);
	}
	free(save);
}
