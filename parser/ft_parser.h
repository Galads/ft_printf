/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:16:23 by brice             #+#    #+#             */
/*   Updated: 2020/11/27 18:16:26 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PARSER_H
#define FT_PARSER_H
#define FLAG_MINUS 0b00000001
#define FLAG_NULL 0b00000010
#define FLAG_DOT 0b00000100
#define FLAG_STAR 0b00000010
#include <stdarg.h>
#include "../processor/ft_processor.h"

typedef struct		save_conversions
{
    va_list v_list;

    unsigned  int  flag;
    int  width;
    int  accuracy;

    int                     bytes;
    /*  short           c;
      short           s;
      short           p;
      short           d;
      short           i;
      short           u;
      short           x;
      short           x_h;
      short           percent;
      short           screen;*/
}                   s_cn;

void                ft_struct_init(s_cn *st_struct);
int                 ft_parser(char *format_proc, s_cn *conv);
void                ft_print_char(char c, s_cn *list);
void                ft_print_string (s_cn *list);
void                ft_print_d(s_cn *list);
#endif