/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:20:09 by brice             #+#    #+#             */
/*   Updated: 2020/12/03 02:20:11 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    ft_print_char (char c, s_cn *list)
{
    char chr;

    chr = va_arg(list->v_list, int);
    if (list->flag & FLAG_MINUS)
    {
        write(1, &chr, 1);
        if (list->width)
        {
            if (list->width != 0)
            {
                while (--list->width)
                {
                    list->bytes++;
                    write(1, " ", 1);
                }
            }
        }
    }
    else
    {
        if (list->width)
        {
            if (list->width != 0)
            {
                while (--list->width)
                {
                    list->bytes++;
                    write(1, " ", 1);
                }
            }
        }
        write(1, &chr, 1);
    }
    list->bytes++;
}
