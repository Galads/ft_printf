/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:16:34 by brice             #+#    #+#             */
/*   Updated: 2021/01/06 18:23:15 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_check_spec_parser(char *str, s_cn *conv)
{
	if (*str == 'c')
		ft_print_char(conv);
	else if (*str == 's')
		ft_print_string(conv);
	else if (*str == 'd')
		ft_print_d(conv);
	else if (*str == 'u')
		ft_print_u(conv, 10);
	else if (*str == 'i')
		ft_print_d(conv);
	else if (*str == 'X')
		ft_print_u(conv, 16);
	else if (*str == 'x')
		ft_print_u(conv, 17);
	else if (*str == 'p')
		ft_print_p(conv);
	else if (*str == '%')
		ft_print_percent(*str, conv);
	else
		return (1);
	return (0);
}

int		ft_parser(char *format_proc, s_cn *conv)
{
	char	format_pr_s;
	conv->bytes = 0;
	while (*format_proc)
	{
		if (*format_proc == '%')
		{
			ft_struct_init(conv);
			if (*format_proc + 1)
				format_proc++;
			format_pr_s = *format_proc;
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
				else if (format_pr_s == '0' && !(conv->flag & FLAG_MINUS))
					conv->flag |= FLAG_NULL;
				if (*format_proc == '.')
					conv->flag |= FLAG_DOT;
				if (ft_isdigit(*format_proc) && !(conv->flag & FLAG_DOT) &&
																!conv->width)
					conv->width = ft_atoi(format_proc);
				else if (ft_isdigit(*format_proc) && conv->flag & FLAG_DOT &&
															!conv->accuracy)
					conv->accuracy = ft_atoi(format_proc);
				if (!(ft_check_spec_parser(format_proc, conv)))
					break ;
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
	return (conv->bytes);
}
