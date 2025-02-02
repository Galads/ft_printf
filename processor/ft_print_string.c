/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:19:53 by brice             #+#    #+#             */
/*   Updated: 2021/01/11 19:45:18 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_helper.h"

static	void	ft_check_first(t_cn *list, char **str, int *accuracy)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->flag |= FLAG_MINUS;
	}
	if (list->accuracy < 0 && *str)
		list->accuracy = (int)ft_strlen(*str);
	if (!*str)
		*str = "(null)";
	else if (!ft_strncmp(*str, "null", 4))
		list->accuracy = 4;
	if (list->accuracy > (int)ft_strlen(*str))
		list->accuracy = (int)ft_strlen(*str);
	*accuracy = list->accuracy;
}

static	void	ft_print_plus(t_cn *list, char **str, int *i, int *accuracy)
{
	while ((*str)[*i] && !(list->flag & FLAG_DOT))
		ft_print_helper(list, str, i);
	while ((*str)[*i] && !list->accuracy && list->flag & FLAG_DOT
											&& (list->flag & FLAG_NULL))
		ft_print_helper(list, str, i);
	while ((*str)[*i] && (*accuracy)--)
		ft_print_helper(list, str, i);
	if (list->flag & FLAG_DOT)
	{
		while (list->width - list->accuracy > 0)
			ft_print_second_helper(list);
	}
	while (list->width - list->accuracy > 0 &&
									list->width - (int)ft_strlen(*str) > 0)
		ft_print_second_helper(list);
}

static	void	ft_print_minus(t_cn *list, char **str, int *i)
{
	while (list->width - list->accuracy > 0 &&
							list->width - (int)ft_strlen(*str) > 0)
		ft_print_second_helper(list);
	if (list->flag & FLAG_DOT)
	{
		while (list->width - list->accuracy > 0 && list->width > 0)
			ft_print_second_helper(list);
	}
	while ((*str)[*i] && list->accuracy--)
		ft_print_helper(list, str, i);
	while ((*str)[*i] && !list->accuracy && list->flag & FLAG_DOT)
		ft_print_helper(list, str, i);
	while ((*str)[*i] && !(list->flag & FLAG_DOT))
		ft_print_helper(list, str, i);
}

void			ft_print_string(t_cn *list)
{
	char	*str;
	int		i;
	int		accuracy;

	i = 0;
	str = va_arg(list->v_list, char *);
	ft_check_first(list, &str, &accuracy);
	if (list->flag & FLAG_MINUS)
		ft_print_plus(list, &str, &i, &accuracy);
	else
		ft_print_minus(list, &str, &i);
}
