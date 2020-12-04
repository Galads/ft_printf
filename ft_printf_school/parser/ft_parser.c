/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:16:34 by brice             #+#    #+#             */
/*   Updated: 2020/11/27 18:16:36 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "ft_parser.h"
#include "../ft_printf.h"

int     ft_check_spec_parser(char *str, s_cn *conv)//cspdiuxX%
{
    if (*str == 'c')
    {
        ft_print_char(*str, conv);
        return (0);
    }
    else if (*str == 's')
    {
        ft_print_string(conv);
        return (0);
    }
    else if (*str == 'd')
    {
        ft_print_d(conv);
        return (0);
    }
    else if (*str == 'u')
    {
        ft_print_u(conv);
        return (0);
    }
    /*else if (*str == 'i')
    {
        ft_processor(conv);
        return (0);
    }
    else if (*str == 'u')
    {
        ft_processor(conv);
        return (0);
    }
    else if (*str == 'x')
    {
        ft_processor(conv);
        return (0);
    }
    else if (*str == 'X')
    {
        ft_processor(conv);
        return (0);
    }*/
        return (1);
}

int    ft_parser(char *format_proc, s_cn *conv)
{
    conv->bytes = 0;
    while (*format_proc)
    {
        if (*format_proc == '%')
        {
            ft_struct_init(conv);
            while (*format_proc)
            {
                if (*format_proc == '*' && !(conv->flag & FLAG_DOT))
                {
                    conv->width = va_arg(conv->v_list, int);
                    format_proc++;
                }
                else if (*format_proc == '*' && (conv->flag & FLAG_DOT))
                {
                    conv->accuracy = va_arg(conv->v_list, int);
                    format_proc++;
                }
                if (*format_proc == '-')
                    conv->flag |= FLAG_MINUS;
                else if (*format_proc == '0' && !(conv->flag & FLAG_MINUS))
                    conv->flag |= FLAG_NULL;
                else if (*format_proc == '.')
                    conv->flag |= FLAG_DOT;
                if (ft_isdigit(*format_proc) && !(conv->flag & FLAG_DOT) && !conv->width)
                    conv->width = ft_atoi(format_proc);
                else if (ft_isdigit(*format_proc) && conv->flag & FLAG_DOT && !conv->accuracy)
                {
                    conv->accuracy = ft_atoi(format_proc);
                    //ft_print_string(conv);
                    //format_proc++;
                    //break;
                }
                if (!(ft_check_spec_parser(format_proc, conv)))
                    break;
                format_proc++;
            }
        }
        else
        {
            conv->bytes++;
            ft_putchar_fd(*format_proc, 1);
        }
        format_proc++;
    }
    //printf("out: %d\n", (conv.flag & FLAG_MINUS));
    return (conv->bytes);
}