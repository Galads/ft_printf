/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:13:28 by brice             #+#    #+#             */
/*   Updated: 2021/01/12 21:30:44 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_parser.h"

int		ft_printf(char *format, ...);

#endif
