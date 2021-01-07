/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:37:28 by brice             #+#    #+#             */
/*   Updated: 2021/01/07 15:53:38 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "ft_helper.h"

static  void	ft_loop_else(s_cn *list, char **str)
{
	while (list->width - list->accuracy > 0 &&
										list->width > (int)ft_strlen(*str))
	{
		list->bytes++;
        list->width--;
        write(1, " ", 1);
    }
}

static void ft_check_minus_sec(s_cn *list, char **str, int *accuracy, int *flag)
{
    if (*accuracy < 0)
    {
		list->accuracy *= -1;
		*accuracy *= -1;
    }
	list->bytes += (int)ft_strlen(*str);
	if (**str == '-' && !(list->flag & FLAG_MINUS))
	{
        list->width--;
        (*str)++;
        *flag = 1;
	}
	while (list->width - list->accuracy > 0  &&
    							list->width > (int)ft_strlen(*str))
	{
        list->bytes++;
        list->width--;
		if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT))
											|| *accuracy < 0)
		{
            write(1, "0", 1);
            continue;
        }
        write(1, " ", 1);
	}
}

static void ft_check_minus_third_helper(s_cn *list, char **str)
{
	while (list->width - ft_strlen(*str) > 0 && list->accuracy)
	{
		write(1, "0", 1);
		list->width--;
		list->bytes++;
	}
}

static void ft_check_minus_third(s_cn *list,char **str, int *accuracy)
{
    if (list->flag & FLAG_DOT && *accuracy > 0)
    {
        while (list->accuracy > (int)ft_strlen(*str))
        {
            write(1, "0", 1);
            list->accuracy--;
            list->bytes++;
        }
    }
    else
		ft_check_minus_third_helper(list, &*str);
    if (**str == '0' && (int)ft_strlen(*str) == 1 &&
    								list->flag & FLAG_DOT && list->width)
    {
        if ((list->flag & FLAG_DOT) && *accuracy)
            write(1, "0", 1);
        else
            write(1," ",1);
    }
    else if (**str == '0' && !*accuracy && list->flag & FLAG_DOT)
        list->bytes--;
    else
        write(1, *str, (int)ft_strlen(*str));
}

void		ft_print_u(s_cn *list, int base) 
{
	char	*str;
    int		accuracy;
    int		flag;

	flag = 0;
    if (!(str = ft_helper_check_u(list, &accuracy, &flag, &base)))
    {
        list->bytes = -1;
        return ;
    }
    if((list->flag & FLAG_MINUS))
    {
        ft_check_minus_helper(list, &str, &accuracy);
        ft_loop_else(list, &str);
    }
    else
    {
		accuracy = list->accuracy;
		flag = 0;
    	ft_check_minus_sec(list, &str, &accuracy, &flag);
        if (flag == 1)
            write(1, "-", 1);
        ft_check_minus_third(list, &str, &accuracy);
    }
}
