/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 18:15:58 by brice             #+#    #+#             */
/*   Updated: 2020/11/27 18:16:00 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

s_cn ft_struct_init(s_cn st_struct)
{
    st_struct.flag = 0;
    st_struct.i = 0;
    st_struct.width = 0;
    st_struct.p = 0;
    st_struct.accuracy = 0;
    st_struct.c = 0;
    st_struct.d = 0;
    st_struct.percent = 0;
    st_struct.s = 0;
    st_struct.u = 0;
    st_struct.x = 0;
    st_struct.x_h = 0;

    return st_struct;
}
