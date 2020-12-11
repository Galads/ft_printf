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

    ft_printf("|%012.4d|\n", 10011);
    printf("|%012.4d|\n", 10011);
    ft_printf("|%011.10d|\n", 222221);
    printf("|%011.10d|\n", 222221);
    ft_printf("|%3.0d|\n", 15);
    printf("|%3.0d|\n", 15);
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

/*
 *               if accuracy  >  width argument !!!!!!!
 */
 /*   ret = ft_printf("m%15.1dm$\n", -4234455);// % in middle
    printf("return: %d\n", ret);


    ret = printf("m%15.1dm$\n", -4234455);// % in middle
    printf("return: %d\n", ret);
*/

//    ret = ft_printf("m%15.25dm$\n", 4234455);// % in middle
//    printf("return: %d\n", ret);
//
//
//    ret = printf("m%15.25dm$\n", 4234455);// % in middle
//    printf("return: %d\n", ret);


    /*
    *	%d
    */
int i = 0;
//s

    /*
    *	%u
    */
//    printf("========================%d==========first========\n", i++);
//    printf("|%d|\n", ft_printf("%u!\n", 42));
//    printf("|%d|\n", printf("%u!\n",  42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%3u!\n", 42));
//    printf("|%d|\n", printf("%3u!\n", 42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%5u!\n", 42));
//    printf("|%d|\n", printf("%5u!\n", 42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%5.3u!\n", 42));
//    printf("|%d|\n", printf("%5.3u!\n", 42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%.u!\n", 42));
//    printf("|%d|\n", printf("%.u!\n", 42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%05.u!\n", -42));
//    printf("|%d|\n", printf("%05.u!\n", -42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%-5.20u!\n", -42));
//    printf("|%d|\n", printf("%-5.20u!\n", -42));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%5.u!\n", 0));
//    printf("|%d|\n", printf("%5.u!\n", 0));
//    printf("========================%d==================\n", i++);
//    printf("|%d|\n", ft_printf("%02d!\n", 0));
//    printf("|%d|\n", printf("%02d!\n", 0));

    /*
     * 	%x
     */

//     printf("|%d|\n", ft_printf("%x!\n", 42));
//     printf("|%d|\n", printf("%x!\n", 42));
//
//     printf("|%d|\n", ft_printf("%3x!\n", 42));
//     printf("|%d|\n", printf("%3x!\n", 42));
//
//     printf("|%d|\n", ft_printf("%5x!\n", 42));
//     printf("|%d|\n", printf("%5x!\n", 42));
//
//     printf("|%d|\n", ft_printf("%5.3x!\n", 42));
//     printf("|%d|\n", printf("%5.3x!\n", 42));
//     printf("|%d|\n", ft_printf("%.x!\n", 42));
//     printf("|%d|\n", printf("%.x!\n", 42));
//     printf("|%d|\n", ft_printf("%05.x!\n", -42));
//     printf("|%d|\n", printf("%05.x!\n", -42));
//     printf("|%d|\n", ft_printf("%-5.20x!\n", -42));
//     printf("|%d|\n", printf("%-5.20x!\n", -42));
//     printf("|%d|\n", ft_printf("%5.x!\n", 0));
//     printf("|%d|\n", printf("%5.x!\n", 0));
//     printf("|%d|\n", ft_printf("%02x!\n", 0));
//     printf("|%d|\n", printf("%02x!\n", 0));

    /*
    *	%X
    */

//     printf("|%d|\n", ft_printf("%X!\n", 42));
//     printf("|%d|\n", printf("%X!\n", 42));
//     printf("|%d|\n", ft_printf("%3X!\n", 42));
//     printf("|%d|\n", printf("%3X!\n", 42));
//     printf("|%d|\n", ft_printf("%5X!\n", 42));
//     printf("|%d|\n", printf("%5X!\n", 42));
//     printf("|%d|\n", ft_printf("%5.3X!\n", 42));
//     printf("|%d|\n", printf("%5.3X!\n", 42));
//     printf("|%d|\n", ft_printf("%.X!\n", 42));
//     printf("|%d|\n", printf("%.X!\n", 42));
//     printf("|%d|\n", ft_printf("%05.X!\n", -42));
//     printf("|%d|\n", printf("%05.X!\n", -42));
//     printf("|%d|\n", ft_printf("%-5.20X!\n", -42));
//     printf("|%d|\n", printf("%-5.20X!\n", -42));
//     printf("|%d|\n", ft_printf("%5.X!\n", 0));
//     printf("|%d|\n", printf("%5.X!\n", 0));
//     printf("|%d|\n", ft_printf("%02X!\n", 0));
//     printf("|%d|\n", printf("%02X!\n", 0));

//     printf("|%d|\n", ft_printf("ft_printf -> %s%15.4sol%5d\texample: %d - %d = %.2d and hex: 42 = %x = %X\n", "hello", "school", 42, 42, 41, 1, -42, -42));
//     printf("|%d|\n", printf("ft_printf -> %s%15.4sol%5d\texample: %d - %d = %.2d and hex: 42 = %x = %X\n", "hello", "school", 42, 42, 41, 1, -42, -42));
//
//     printf("|%d|\n", ft_printf("avc%13s24343%-5.2s\n", "ABC", "abc"));
//     printf("|%d|\n", printf("avc%13s24343%-5.2s\n", "ABC", "abc"));
//
//     printf("|%d|\n", ft_printf("\%123%5d\n", 42));
//     printf("|%d|\n", printf("\%123%5d\n", 42));
//
//     printf("|%d|\n", ft_printf("%03d\n", 634));
//     printf("|%d|\n", printf("%03d\n", 634));
//     printf("|%d|\n", ft_printf("%.*X", -1, 12345));
//     printf("|%d|\n", printf("%.*X", -1, 12345));
//
//     printf("|%d|\n", ft_printf("%.*s\n", -1, 0));
//     printf("|%d|\n", printf("%.*s\n", -1, 0));
//     printf("|%d|\n", ft_printf("%.*s\n", -3, 0));
//     printf("|%d|\n", printf("%.*s\n", -3, 0));
//
//     printf("|%d|\n", printf("%.1da\n", 0));
//     printf("|%d|\n", ft_printf("%.1da\n", 0));
//    printf("%u\n", -42);
//     ft_printf("%q\n");
//     printf("%q\n");
//
//
//    ret = printf("m%22.3dm$\n", -42);// % in middle
//    printf("return: %d\n", ret);
//    printf("$%5%$\n");

    /*
    *	%p
    */

    // printf("|%d|\n", ft_printf("%p!\n", "42"));
    // printf("|%d|\n", printf("%p!\n", "42"));
    // printf("|%d|\n", ft_printf("%3p!\n", 42));
    // printf("|%d|\n", printf("%3p!\n", 42));
    // printf("|%d|\n", ft_printf("%5p!\n", 42));
    // printf("|%d|\n", printf("%5p!\n", 42));
    // printf("|%d|\n", ft_printf("%5.3p!\n", 42));
    // printf("|%d|\n", printf("%5.3p!\n", 42));
    // printf("|%d|\n", ft_printf("%.p!\n", 42));
    // printf("|%d|\n", printf("%.p!\n", 42));
    // printf("|%d|\n", ft_printf("%05.p!\n", -42));
    // printf("|%d|\n", printf("%05.p!\n", -42));
    // printf("|%d|\n", ft_printf("%-5.20p!\n", -42));
    // printf("|%d|\n", printf("%-5.20p!\n", -42));
    // printf("|%d|\n", ft_printf("%.p!\n", 42));
    // printf("|%d|\n", printf("%.p!\n", 42));

    // printf("|%d|\n", ft_printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", ft_printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", ft_printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", printf("%*.p!\n", 0, 0));
    // printf("|%d|\n", ft_printf("%16.p!\n", 0));
    // printf("|%d|\n", printf("%16.p!\n", 0));
    // printf("|%d|\n", ft_printf("%--16.p!\n", 0, 0));
    // printf("|%d|\n", printf("%--16.p!\n", 0, 0));
    // printf("|%d|\n", ft_printf("%3.p!\n", 0));
    // printf("|%d|\n", printf("%3.p!\n", 0));
    // printf("|%d|\n", ft_printf("%5p!\n", 0));
    // printf("|%d|\n", printf("%5p!\n", 0));

    // printf("|%d|\n", ft_printf("%5%!\n"));
    // printf("|%d|\n", printf("%5%!\n"));
    // printf("|%d|\n", ft_printf("%5.%!\n"));
    // printf("|%d|\n", printf("%5.%!\n"));
    // printf("|%d|\n", ft_printf("%-5%!\n"));
    // printf("|%d|\n", printf("%-5%!\n"));
    // printf("|%d|\n", ft_printf("%-5.%!\n"));
    // printf("|%d|\n", printf("%-5.%!\n"));
    // printf("|%d|\n", ft_printf("%-05%!\n"));
    // printf("|%d|\n", printf("%-05%!\n"));
    // printf("|%d|\n", ft_printf("%-05.%!\n"));
    // printf("|%d|\n", printf("%-05.%!\n"));
    // printf("|%d|\n", ft_printf("%05.%!\n"));
    // printf("|%d|\n", printf("%05.%!\n"));

    // printf("|%d|\n", ft_printf("%% *.5i 42 == |% *.5i|\n", 4, 42));
    // printf("|%d|\n", printf("%% *.5i 42 == |% *.5i|\n", 4, 42));
    // printf("|%d|\n", ft_printf("% *.5i!\n", 4, 42));
    // printf("|%d|\n", printf("% *.5i!\n", 4, 42));
    // printf("|%d|\n", ft_printf("%4.5i!\n", 42));
    // printf("|%d|\n", printf("%4.5i!\n", 42));


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