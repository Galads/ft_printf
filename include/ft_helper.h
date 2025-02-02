/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brice <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:16:16 by brice             #+#    #+#             */
/*   Updated: 2021/01/12 17:54:51 by brice            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPER_H
# define FT_HELPER_H
# include <unistd.h>
# include <stdlib.h>
# include "ft_parser.h"

void	ft_helper_print(t_cn *list, char **str, int *accuracy, int *flag);
void	ft_helper_print_second(t_cn *list, char **str, int *accuracy);
char	*ft_helper_check_u(t_cn *list, int *accuracy, int *flag, int *base);
void	ft_check_minus_helper(t_cn *list, char **str, int *accuracy);
void	ft_while_print_null_helper(t_cn *list, char **str);
void	ft_print_helper_plus(t_cn *list, char **str, int *i, int *accuracy);
void	ft_print_helper(t_cn *list, char **str, int *i);
void	ft_print_second_helper(t_cn *list);
void	ft_first_check_d_help(t_cn *list);

#endif
