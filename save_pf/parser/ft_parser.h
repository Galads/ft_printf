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


#ifndef FT_PRINTF_SCHOOL_FT_PARSER_H
#define FT_PRINTF_SCHOOL_FT_PARSER_H

typedef struct		save_conversions
{
    unsigned int    flag;
    unsigned int    width;
    unsigned int    accuracy;
    short           c;
    short           s;
    short           p;
    short           d;
    short           i;
    short           u;
    short           x;
    short           x_h;
    short           percent;
    short           screen;
}                   s_cn;

s_cn                ft_struct_init(s_cn st_struct);

#endif //FT_PRINTF_SCHOOL_FT_PARSER_H
