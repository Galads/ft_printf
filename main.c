
#include "./libft/libft.h"
#include "./parser/ft_parser.h"
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
        {
            conv.flag = '-';
            format_proc++;
        }
        else if (*format_proc == '0')
        {
            conv.flag = '0';
            format_proc++;
        }
        else if (*format_proc == '+')
        {
            conv.flag = '+';
            *format_proc++;
        }
        else if (*format_proc == ' ')
        {
            conv.flag = ' ';
            *format_proc++;
        }
        else if (*format_proc == '%')
        {
            conv.screen = '%';
            return;
        }
    }
    //format_proc++;
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
    printf("flag -> %c or -> %%d %d\n", conv.flag, conv.flag);
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
    char *str = "%6666s";
    char *set;

    //ft_init_args("sgsd", 5, "abc", 'H');

    set = ft_strchr(str, '%');
    ft_parser(set, conv);

    printf("|+++++++++++++++++1++++++++++++++++++++|\n|+++++++++++++++++++1++++++++++++++++++|\n");
    char  *str1 = "%045.5d";
    char  *set1;
    ft_struct_init(conv);
    set1 = ft_strchr(str1, '%');
    ft_parser(set1, conv);


    printf("|+++++++++++++++++2++++++++++++++++++++|\n|++++++++++++++++++++2+++++++++++++++++|\n");
    char  *str2 = "%.5X";
    char  *set2;
    ft_struct_init(conv);
    set2 = ft_strchr(str2, '%');
    ft_parser(set2, conv);

    printf("|+++++++++++++++++3++++++++++++++++++++|\n|++++++++++++++++++++3+++++++++++++++++|\n");
    char  *str3 = "11123413123123132%0.200u";
    char  *set3;
    ft_struct_init(conv);
    set3 = ft_strchr(str3, '%');
    ft_parser(set3, conv);

   // printf("+++++++++++++++++++++test3++++++++++++++++++++++\noriginal printf = %-.200s\n", "faqqwdad");

    printf("|+++++++++++++++++4++++++++++++++++++++|\n|++++++++++++++++++++4+++++++++++++++++|\n");
    char  *str4 = "11123413123123132%+5d";
    char  *set4;
    ft_struct_init(conv);
    set4 = ft_strchr(str4, '%');
    ft_parser(set4, conv);

    printf("|+++++++++++++++++5++++++++++++++++++++|\n|++++++++++++++++++++5+++++++++++++++++|\n");
    char  *str5 = "11123413123123132% 5d";
    char  *set5;
    ft_struct_init(conv);
    set5 = ft_strchr(str5, '%');
    ft_parser(set5, conv);

    // printf("orig printf = %10.*d", 5, 1);

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