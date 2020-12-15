/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:19:53 by brice             #+#    #+#             */
/*   Updated: 2020/12/03 02:19:57 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"
#include "../libft/libft.h"

void    ft_print_string(s_cn *list)
{
    char *str;
    int i;
    int len;

    i = 0;
    len = list->accuracy;
    str = va_arg(list->v_list, char *);
    if (list->flag & FLAG_MINUS && list->flag & FLAG_DOT)
    {
        while (str[i])
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i] && list->accuracy--)
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while ((list->width - i) > 0 && (list->width - ft_strlen(str)))
        {
            write(1, " ", 1);
            list->width--;
            list->bytes++;
        }
    }
    else
    {
        while ((list->width - len) > 0 && (list->width - ft_strlen(str)))
        {
            write(1, " ", 1);
            list->width--;
            list->bytes++;
        }
        while (str[i] && list->accuracy--)
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
        while (str[i])
        {
            write(1, &str[i++], 1);
            list->bytes++;
        }
    }
}