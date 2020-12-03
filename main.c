#include "./libft/libft.h"
#include "./parser/ft_parser.h"
#include "./processor/ft_processor.h"
#include "ft_printf.h"

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


int		main()
{
    s_cn conv;

    ft_struct_init(&conv);
    char *str = "%6666s";
    char *set;

    int ret = 0;
/*
    ret = ft_printf("musor %-10c musor %10c %*c$\n", 'F', '5', 0, 'q');// % in middle

    //ret = ft_printf("m %*c$\n", 2, 'q');
    printf("return: %d\n", ret);

    ret = ft_printf("musor %10c  %000000010c %-*c$\n", 'F', '5', 5, 'q');// % in middle
    printf("return: %d\n", ret);

    printf("+++++++++++++++++++++++++test string+++++++++++++++++++++++++\n");
    ret = ft_printf("m%-5sm$\n", "abc");// % in middle
    printf("return: %d\n", ret);

    ret = printf("m%-5sm$\n", "abc");// % in middle
    printf("return: %d\n", ret);
    printf("=============================================================\n");
    ret = ft_printf("m%5sm$\n", "abc");// % in middle
    printf("return: %d\n", ret);

    ret = printf("m%5sm$\n", "abc");// % in middle
    printf("return: %d\n", ret);

    printf("=============================================================\n");
    ret = ft_printf("m%-20sm$\n", "123");// % in middle
    printf("return: %d\n", ret);

    ret = printf("m%-20sm$\n", "123");// % in middle
    printf("return: %d\n", ret);

    printf("=============================================================\n");

    ret = ft_printf("m%55.0sm$\n", "123456");// % in middle
    printf("return: %d\n", ret);

    ret = printf("m%55.0sm$\n", "123456");// % in middle
    printf("return: %d\n", ret);
*/
                        /*
                         * i
                         */
    // printf("|%d|\n", ft_printf("%i!\n", 42));
    // printf("|%d|\n", printf("%i!\n", 42));
    // printf("|%d|\n", ft_printf("%3i!\n", 42));
    // printf("|%d|\n", printf("%3i!\n", 42));
    // printf("|%d|\n", ft_printf("%5i!\n", 42));
    // printf("|%d|\n", printf("%5i!\n", 42));
    // printf("|%d|\n", ft_printf("%5.3i!\n", 42));
    // printf("|%d|\n", printf("%5.3i!\n", 42));
    // printf("|%d|\n", ft_printf("%.i!\n", 42));
    // printf("|%d|\n", printf("%.i!\n", 42));
    // printf("|%d|\n", ft_printf("%05.i!\n", -42));
    // printf("|%d|\n", printf("%05.i!\n", -42));
    // printf("|%d|\n", ft_printf("%30.30i!\n", -42));
    // printf("|%d|\n", printf("%30.30i!\n", -42));
    // printf("|%d|\n", ft_printf("%5.i!\n", 0));
    // printf("|%d|\n", printf("%5.i!\n", 0));
    // printf("|%d|\n", ft_printf("%02i!\n", 0));
    // printf("|%d|\n", printf("%02i!\n", 0));
    // printf("|%d|\n", ft_printf("%03i!\n", 634));
    // printf("|%d|\n", printf("%03i!\n", 634));


 //   ret = ft_printf("m%22.3dm$\n", -42);// % in middle
   // printf("return: %d\n", ret);

    ret = ft_printf("m%.23dm$\n", -42);// % in middle
    printf("return: %d\n", ret);

    ret = printf("m%.23dm$\n", -42);// % in middle
    printf("return: %d\n", ret);

 //   ret = printf("m%22.3dm$\n", -42);// % in middle
//    printf("return: %d\n", ret);
   // printf("$%5%$\n");



    //printf(" bytes: ++++%d++++\n", printf("123123"));
/*
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

    printf("|+++++++++++++++++6++++++++++++++++++++|\n|++++++++++++++++++++6+++++++++++++++++|\n");
    char  *str6 = "11123413123123132%-0000000005d";
    char  *set6;
    ft_struct_init(conv);
    set6 = ft_strchr(str6, '%');
    ft_parser(set6, conv);

    printf("|+++++++++++++++++Z-F++++++++++++++++++++|\n|+++++++++++++++++++Z-F+++++++++++++++++|\n");
    printf("++++++++++++++++%-0.8d", 555);

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
    */
}