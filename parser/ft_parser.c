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
#include <stdio.h>
#include <stdarg.h>

void	ft_test(char *format, ...)
{
    va_list		ap; // argptr
   // printf("0 -> %s\n");

    va_start(ap, format);
    int a = va_arg(ap, int);
    printf("1 -> %d\n", a);
    char *s = va_arg(ap, char *);
    printf("2 -> %s\n", s);
    char c = va_arg(ap, int);
    printf("3 -> %c\n", c);
    va_end(ap);
}

void ft_init_args(char *format, ...)
{
    va_list ap;

}
void ft_parser(char *format_proc, s_cn conv)
{
    int flag = 1;

    format_proc++;
    if (*format_proc) {
        if (*format_proc == '-')
            conv.flag = '-';
        else if (*format_proc == '0')
            conv.flag = '0';
    }
    format_proc++;
    while (*format_proc == '*' || (*format_proc >= '0' && *format_proc <= '9')) {
        if (*format_proc == '*')
            conv.width = '*';
        else if (*format_proc >= '0' && *format_proc <= '9' && flag) {
            conv.width = ft_atoi(format_proc);
            flag = 0;
        }
        format_proc++;
    }
    flag = 1;
    if (*format_proc == '.') {
        format_proc++;
        while (*format_proc == '*' || (*format_proc >= '0' && *format_proc <= '9')) {
            if (*format_proc == '*')
                conv.accuracy = '*';
            else if (*format_proc >= '0' && *format_proc <= '9' && flag) {
                conv.accuracy = ft_atoi(format_proc);
                flag = 0;
            }
            format_proc++;
        }
    }

    if (*format_proc == 'c')
        conv.c = 1;
    else if (*format_proc == 's')
        conv.s = 1;
    else if (*format_proc == 'p')
        conv.p = 1;
    else if (*format_proc == 'd')
        conv.d = 1;
    else if (*format_proc == 'i')
        conv.i = 1;
    else if (*format_proc == 'u')
        conv.u = 1;
    else if (*format_proc == 'x')
        conv.x = 1;
    else if (*format_proc == 'X')
        conv.x_h = 1;
    else if (*format_proc == '%')
        conv.percent = 1;

    //printf("%c", *(format_proc + 1));
    printf("flag -> %c\n", conv.flag);
    printf("width_dec -> %d  width_char -> %c\n", conv.width, conv.width);
    printf("accuracy -> %d or  %c \n", conv.accuracy, conv.accuracy);

    printf("conv.c = %d\n", conv.c);
    printf("conv.s = %d\n", conv.s);
    printf("conv.p = %d\n", conv.p);
    printf("conv.d = %d\n", conv.d);
    printf("conv.i = %d\n", conv.i);
    printf("conv.u = %d\n", conv.u);
    printf("conv.x = %d\n", conv.x);
    printf("conv.x_h = %d\n", conv.x_h);
    printf("conv.percent = %d\n", conv.percent);
}

int		main()
{
    s_cn conv;
    conv = ft_struct_init(conv);
    char *str = "%s";
    char *set;

    //ft_init_args("sgsd", 5, "abc", 'H');

    set = ft_strchr(str, '%');
    ft_parser(set, conv);

    printf("orig printf = %10.*d", 5, 1);
    //printf("%c", c)


    // printf("%d\n", st.precision);
    // printf("%d\n", st.width);
    // printf("%d\n", st.enumerate.star);
    // char *s = "Hello, World!";
    // char s1[] = "Hello, world!";
    // int n = -1024;
    // printf("string -> |%0-15.15s|\n", s);
    // printf("string -> |%2s|\n", s1);
    // printf("int <1024> -> |%7d|\n\n", n);
    // //ft_test("", 45, "Hello", 'A');
    // printf("|%14.14s|\n", s);
    // printf("%13.12s\n", s);
    // printf("|%-.15s|\n", s);
    // printf("%zzz%d\n", 5);
    // printf("%.123242\n", s);
    // printf("%X\n", NULL);
    //printf(NULL);
}

/*
int main()
{
   // printf("+++++++++%-5d++++++++++++\n", 25);
   // printf("+++++++++%5d++++++++++++\n", 25);
}
*/
