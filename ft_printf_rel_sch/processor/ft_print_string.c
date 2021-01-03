/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:19:53 by brice             #+#    #+#             */
/*   Updated: 2021/01/03 15:58:58 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_parser.h"

void    ft_print_string(s_cn *list)
{
    char *str;
    int i;
    int accuracy;

    i = 0;
    str = va_arg(list->v_list, char *);
    if(list->width < 0)
    {
        list->width *= -1;
        list->flag |= FLAG_MINUS;
    }
    if (list->accuracy < 0)
        list->accuracy = ft_strlen(str);
    if (!str)
        str = "(null)";
    else if (!ft_strncmp(str, "null", 4))
        list->accuracy = 4;
    if (list->accuracy > (int)ft_strlen(str))
        list->accuracy = ft_strlen(str);
    accuracy = list->accuracy;
    if (list->flag & FLAG_MINUS)
    {
        while (str[i] && !(list->flag & FLAG_DOT))
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i] && !list->accuracy && list->flag & FLAG_DOT && (list->flag & FLAG_NULL))
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i] && accuracy--)
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        if (list->flag & FLAG_DOT)
        {
            while (list->width - list->accuracy > 0)
            {
                list->width--;
                list->bytes++;
                write(1, " ", 1);
            }
        }
        while (list->width - list->accuracy > 0 && list->width - (int)ft_strlen(str) > 0)
        {
            list->width--;
            list->bytes++;
            write(1, " ", 1);
        }
    }
    else
    {
        while (list->width - list->accuracy > 0 && list->width - (int)ft_strlen(str) > 0)
        {
            list->width--;
            list->bytes++;
            write(1, " ", 1);
        }
        if (list->flag & FLAG_DOT)
        {
            while (list->width - list->accuracy > 0)
            {
                list->width--;
                list->bytes++;
                write(1, " ", 1);
            }
        }
        while (str[i] && list->accuracy--)
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i] && !list->accuracy && list->flag & FLAG_DOT)
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i] && !(list->flag & FLAG_DOT))
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
    }
}
