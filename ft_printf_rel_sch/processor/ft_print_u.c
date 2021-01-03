/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:37:28 by brice             #+#    #+#             */
/*   Updated: 2020/12/21 17:00:22 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void		ft_print_u(s_cn *list, int base) {
    char    *str;
    int     accuracy;
    int     flag;

    flag = 0;
	accuracy = list->accuracy;
    if (base == 17)
    {
        flag = 1;//111
        base--;
    }
    str = ft_itoa_base_xu(va_arg(list->v_list, unsigned int), base);
    if (flag == 1)//111
    {
        flag = 0;
        while (str[flag])
        {
            str[flag] = (char)ft_tolower(str[flag]);
            flag++;
        }
    }

    if (list->width < 0)
    {
        list->width *= -1;
        list->flag |= FLAG_MINUS;
    }
    if((list->flag & FLAG_MINUS))
    {
        if (*str == '-' && (list->flag & FLAG_MINUS))
        {
            list->width--;
            str++;
            write(1, "-", 1);
            list->bytes++;
            while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
            {
                write(1, "0", 1);
                list->accuracy--;
                list->bytes++;
                list->width--;
            }
        }
        while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
        {
            write(1, "0", 1);
            list->accuracy--;
            list->bytes++;
            list->width--;
        }
        if (*str == '0'&& list->flag & FLAG_DOT && !accuracy)// no if 
            write(1, " ", ft_strlen(str));//
        else//
            write(1, &*str, ft_strlen(str));//
        list->bytes += ft_strlen(str);
        while (list->width - list->accuracy > 0 && list->width > (int)ft_strlen(str))
        {
            list->bytes++;
            list->width--;
            write(1, " ", 1);
        }
    }
    else
    {
        accuracy = list->accuracy;
        if (accuracy < 0)
        {
            list->accuracy *= -1;
            accuracy *= -1;
        }
        flag = 0;
        list->bytes += ft_strlen(str);
        if (*str == '-' && !(list->flag & FLAG_MINUS))
        {
            list->width--;
            str++;
            flag = 1;
        }
        while (list->width - list->accuracy > 0  && list->width > (int)ft_strlen(str))
        {
            list->bytes++;
            list->width--;
            // list->accuracy--;
            if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT)) || accuracy < 0)
            {
                write(1, "0", 1);
                continue;
            }
            write(1, " ", 1);
        }
        if (flag == 1)
            write(1, "-", 1);
        if (list->flag & FLAG_DOT && accuracy > 0)
        {
            while (list->accuracy > (int)ft_strlen(str))
            {
                write(1, "0", 1);
                list->accuracy--;
                list->bytes++;
            }
        }
        else
        {
            while (list->width - ft_strlen(str) > 0 && list->accuracy)
            {
                write(1, "0", 1);
                list->width--;
                list->bytes++;
            }
        }
        if (*str == '0' && ft_strlen(str) == 1 && list->flag & FLAG_DOT && list->width) //&& ft_strlen(str) == 1 && //!accuracy
        {
            if ((list->flag & FLAG_DOT) && accuracy)//&& !(list->width))
                write(1, "0", 1);
            else
                write(1," ",1);
        }
        else if (*str == '0' && !accuracy && list->flag & FLAG_DOT)
        {
//            write(1, "X", 1);
            list->bytes--;
        }
        else
            write(1, &*str, ft_strlen(str));
    }
}
