/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:16:23 by brice             #+#    #+#             */
/*   Updated: 2021/01/08 19:23:35 by brice            ###   ########.fr       */
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

typedef	struct		s_convn
{
	va_list			v_list;
	unsigned int	flag;
	int				width;
	int				accuracy;
	int				bytes;
}					t_cn;

void				ft_struct_init(t_cn *st_struct);
int					ft_parser(char *format_proc, t_cn *conv);
void				ft_print_char(t_cn *list);
void				ft_print_string (t_cn *list);
void				ft_print_d(t_cn *list);
void				ft_print_u(t_cn *list, int base);
void				ft_print_p(t_cn *list);
char				*ft_itoa_base_xu(unsigned int n, int base);
char				*ft_itoa_base_ull(unsigned long long int n, int base);
void				ft_print_percent(char c, t_cn *list);

#endif
