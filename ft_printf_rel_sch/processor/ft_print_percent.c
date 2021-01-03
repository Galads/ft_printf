/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 05:35:04 by brice             #+#    #+#             */
/*   Updated: 2020/12/19 05:35:45 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"
void    ft_print_percent(char c, s_cn *list)
{
    char chr;

    chr = '%';
	c = '0';

    if (list->width < 0)
    {
        list->width *= -1;
        list->flag |= FLAG_MINUS;
    }
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
                    if (list->flag & FLAG_NULL)
                    {
                        write(1, "0", 1);
                        continue;
                    }
                    write(1, " ", 1);
                }
            }
        }
        write(1, &chr, 1);
    }
    list->bytes++;
}
