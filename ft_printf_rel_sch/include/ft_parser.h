/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:16:23 by brice             #+#    #+#             */
/*   Updated: 2020/12/19 05:24:02 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# define FLAG_MINUS 0b00000001
# define FLAG_NULL 0b00000010
# define FLAG_DOT 0b00000100
# define FLAG_STAR 0b00000010

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
//# include "./ft_processor.h"

typedef	struct		save_conversions
{
	va_list			v_list;
	unsigned int	flag;
	int				width;
	int				accuracy;
	int				bytes;
}					s_cn;

void				ft_struct_init(s_cn *st_struct);
int					ft_parser(char *format_proc, s_cn *conv);
void				ft_print_char(s_cn *list);
void				ft_print_string (s_cn *list);
void				ft_print_d(s_cn *list);
void				ft_print_u(s_cn *list, int base);
void				ft_print_p(s_cn *list);
char				*ft_itoa_base_xu(unsigned int n, int base);
char				*ft_itoa_base_ull(unsigned long long int n, int base);
void				ft_print_percent(char c, s_cn *list);

#endif
