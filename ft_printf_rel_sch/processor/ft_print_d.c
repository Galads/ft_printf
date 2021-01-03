#include "ft_printf.h"
#include "ft_parser.h"
//#include "../libft/libft.h"

void    ft_print_d(s_cn *list)
{
//    char    *str;
//    int     accuracy;
//    int     flag;
//
//    str = ft_itoa(va_arg(list->v_list, int));
//    if (list->width < 0)
//    {
//        list->width *= -1;
//        //list->accuracy *= -1;
//        list->flag |= FLAG_MINUS;
//    }
////    if (list->accuracy < 0)
////    {
////        list->accuracy *= -1;
////        //list->flag |= FLAG_MINUS;
////    }
//    if((list->flag & FLAG_MINUS))
//    {
//        if (*str == '-' && (list->flag & FLAG_MINUS))
//        {
//            list->width--;
//            str++;
//            write(1, "-", 1);
//            list->bytes++;
//            while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
//            {
//                write(1, "0", 1);
//                list->accuracy--;
//                list->bytes++;
//                list->width--;
//            }
//        }
//        while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
//        {
//            write(1, "0", 1);
//            list->accuracy--;
//            list->bytes++;
//            list->width--;
//        }
//        write(1, &*str, ft_strlen(str));
//        list->bytes += ft_strlen(str);
//        while (list->width - list->accuracy > 0 && list->width > (int)ft_strlen(str))
//        {
//            list->bytes++;
//            list->width--;
//            write(1, " ", 1);
//        }
//    }
//    else
//    {
//        accuracy = list->accuracy;
//        if (accuracy < 0)
//            list->accuracy *= -1;
//        flag = 0;
//        list->bytes += ft_strlen(str);
//        if (*str == '-' && !(list->flag & FLAG_MINUS) && !(list->flag & FLAG_NULL))
//        {
//            list->width--;
//            str++;
//            flag = 1;
//        }
//		else if (*str == '-' && list->flag & FLAG_NULL)
//        {
//            list->width--;
//            str++;
//            write(1, "-", 1);
//        }
//        while (list->width - list->accuracy > 0  && list->width > (int)ft_strlen(str))
//        {
//            list->bytes++;
//            list->width--;
//           // list->accuracy--;
//            if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT)) || accuracy < 0)
//            {
//                write(1, "0", 1);
//                continue;
//            }
//            write(1, " ", 1);
//        }
//        if (flag == 1 && !(list->flag & FLAG_NULL))
//			write(1, "-", 1);
//        if (list->flag & FLAG_DOT && accuracy > 0)
//        {
//            while (list->accuracy > (int)ft_strlen(str))
//            {
//                write(1, "0", 1);
//                list->accuracy--;
//                list->bytes++;
//            }
//        }
//        else
//        {
//            while (list->width - (int)ft_strlen(str) > 0)
//            {
//                write(1, "0", 1);
//                list->width--;
//                list->bytes++;
//            }
//        }
////        if (*str == '0') //&& ft_strlen(str) == 1 &&
////        {
////            if (list->flag & FLAG_NULL)
////                write(1, "0", 1);
////            else
////                write(1," ",1);
////        }
////        else
////            write(1, &*str, ft_strlen(str));
//        if (*str == '0' && ft_strlen(str) == 1 && list->flag & FLAG_DOT && list->width) //&& ft_strlen(str) == 1 && //!accuracy
//        {
//            if ((list->flag & FLAG_DOT) && accuracy)//&& !(list->width))
//                write(1, "0", 1);
//            else
//                write(1," ",1);
//        }
//        else if (*str == '0' && !accuracy && list->flag & FLAG_DOT)
//        {
//            list->bytes--;
//        }
//        else
//            write(1, &*str, ft_strlen(str));
//	}
  // code rev 2
//        char    *str;
//        int     accuracy;
//        int     flag;
//
//        str = ft_itoa(va_arg(list->v_list, int)); // return -1;
//        if (list->width < 0)
//        {
//            list->width *= -1;
//            //list->accuracy *= -1;
//            list->flag |= FLAG_MINUS;
//        }
//    //    if (list->accuracy < 0)
//    //    {
//    //        list->accuracy *= -1;
//    //        //list->flag |= FLAG_MINUS;
//    //    }
//        if((list->flag & FLAG_MINUS))
//        {
//            if (*str == '-' && (list->flag & FLAG_MINUS))
//            {
//                list->width--;
//                str++;
//                write(1, "-", 1);
//                list->bytes++;
//                while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
//                {
//                    write(1, "0", 1);
//                    list->accuracy--;
//                    list->bytes++;
//                    list->width--;
//                }
//            }
//            while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
//            {
//                write(1, "0", 1);
//                list->accuracy--;
//                list->bytes++;
//                list->width--;
//            }
//            write(1, &*str, ft_strlen(str));
//            list->bytes += ft_strlen(str);
//            while (list->width - list->accuracy > 0 && list->width > (int)ft_strlen(str))
//            {
//                list->bytes++;
//                list->width--;
//                write(1, " ", 1);
//            }
//        }
//        else
//        {
//            accuracy = list->accuracy;
//            if (accuracy < 0) //&& !list->accuracy)
//                list->accuracy *= -1;
//            flag = 0;
//            list->bytes += ft_strlen(str);
//            if (*str == '-' && !(list->flag & FLAG_MINUS) && !(list->flag & FLAG_NULL))
//            {
//                list->width--;
//                str++;
//                flag = 1;
//            }
//            else if (*str == '-' && list->flag & FLAG_NULL && !list->accuracy && !(list->flag & FLAG_DOT))
//            {
//                list->width--;
//                str++;
//                write(1, "-", 1);
//            }
//            while (list->width - list->accuracy > 0  && list->width > (int)ft_strlen(str))
//            {
//                list->bytes++;
//                list->width--;
//               // list->accuracy--;
//                if (*str == '-' && list->width == list->accuracy && list->accuracy > 0 &&
//						list->accuracy > (int)ft_strlen(str))
//                {
//    //                str++;
//                    list->bytes--;
//                    write(1, "-", 1);
//                    continue;
//                }
//                if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT)) || accuracy < 0)
//                {
//                    write(1, "0", 1);
//                    continue;
//                }
//                if (*str == '-' && list->accuracy == (int)ft_strlen(str) && list->width == list->accuracy)
//                    break;
//                write(1, " ", 1);
//            }
//            if (flag == 1 && !(list->flag & FLAG_NULL))
//                write(1, "-", 1);
//            if (list->flag & FLAG_DOT && accuracy > 0)
//            {
//                if (*str == '-' && list->accuracy > (int)ft_strlen(str))
//                {
//                    str++;
//    //                write(1, "0", 1);
//                }
//                while (list->accuracy > (int)ft_strlen(str))
//                {
//                    write(1, "0", 1);
//                    list->accuracy--;
//                    list->bytes++;
//                }
//            }
//            else
//            {
//                while (list->width - (int)ft_strlen(str) > 0)
//                {
//                    write(1, "0", 1);
//                    list->width--;
//                    list->bytes++;
//                }
//            }
//    //        if (*str == '-' && list->width && list->accuracy)
//    //            str++;
//    //        if (*str == '0') //&& ft_strlen(str) == 1 &&
//    //        {
//    //            if (list->flag & FLAG_NULL)
//    //                write(1, "0", 1);
//    //            else
//    //                write(1," ",1);
//    //        }
//    //        else
//    //            write(1, &*str, ft_strlen(str));
//            if (*str == '0' && ft_strlen(str) == 1 && list->flag & FLAG_DOT && list->width) //&& ft_strlen(str) == 1 && //!accuracy
//            {
//                if ((list->flag & FLAG_DOT) && accuracy)//&& !(list->width))
//                    write(1, "0", 1);
//                else
//                    write(1," ",1);
//            }
//            else if (*str == '0' && !accuracy && list->flag & FLAG_DOT)
//            {
//                list->bytes--;
//            }
//            else
//            {
//                if (*str == '-' && accuracy == (int)ft_strlen(str))
//                {
//                    str++;
//                    write(1, "-0", 2);
//                }
//                write(1, &*str, ft_strlen(str));
//            }
//        }
//    code rev 3
        char    *str;
        int     accuracy;
        int     flag;

        str = ft_itoa(va_arg(list->v_list, int)); // return -1;
        if (list->width < 0)
        {
            list->width *= -1;
            //list->accuracy *= -1;
            list->flag |= FLAG_MINUS;
        }
    //    if (list->accuracy < 0)
    //    {
    //        list->accuracy *= -1;
    //        //list->flag |= FLAG_MINUS;
    //    }
        if((list->flag & FLAG_MINUS))
        {
            if (*str == '-' && (list->flag & FLAG_MINUS))
            {
                list->width--;
                str++;
                write(1, "-", 1);
                list->bytes++;
                while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
                {
                    write(1, "0", 1);
                    list->accuracy--;
                    list->bytes++;
                    list->width--;
                }
            }
            while (list->accuracy > (int)ft_strlen(str) && list->accuracy > 0)
            {
                write(1, "0", 1);
                list->accuracy--;
                list->bytes++;
                list->width--;
            }
            if (*str == '0'&& (list->flag & FLAG_DOT) && list->accuracy == 0)
                write(1, " ", 1);
            else
                write(1, &*str, ft_strlen(str));;
            list->bytes += ft_strlen(str);
            while (list->width - list->accuracy > 0 && list->width > (int)ft_strlen(str))
            {
                list->bytes++;
                list->width--;
                write(1, " ", 1);
            }
        }
        else
        {
            accuracy = list->accuracy;
            if (accuracy < 0) //&& !list->accuracy)
                list->accuracy *= -1;
            flag = 0;
            list->bytes += ft_strlen(str);
            if (*str == '-' && !(list->flag & FLAG_MINUS) && !(list->flag & FLAG_NULL))
            {
                list->width--;
                str++;
                flag = 1;
            }
            else if (*str == '-' && list->flag & FLAG_NULL && !list->accuracy && !(list->flag & FLAG_DOT))
            {
                list->width--;
                str++;
                write(1, "-", 1);
            }
            while (list->width - list->accuracy > 0  && list->width > (int)ft_strlen(str))
            {
                list->bytes++;
                list->width--;
               // list->accuracy--;
                if (*str == '-' && list->width == list->accuracy && list->accuracy > 0 && list->accuracy > (int)ft_strlen(str))
                {
                    str++;
                    list->bytes--;
                    write(1, "-", 1);
                    continue;
                }
                if ((list->flag & FLAG_NULL && !(list->flag & FLAG_DOT)) || accuracy < 0)
                {
                    write(1, "0", 1);
                    continue;
                }
                if (*str == '-' && list->accuracy == (int)ft_strlen(str) && list->width == list->accuracy)
                    break;
                write(1, " ", 1);
            }
            if (flag == 1 && !(list->flag & FLAG_NULL))
                write(1, "-", 1);
            if (list->flag & FLAG_DOT && accuracy > 0)
            {
                if (*str == '-' && list->accuracy > (int)ft_strlen(str) && list->accuracy > list->width)
                {
                    str++;
                    write(1, "-", 1);
    //                list->accuracy--;
                }
                while (list->accuracy > (int)ft_strlen(str))
                {
                    write(1, "0", 1);
                    list->accuracy--;
                    list->bytes++;
                }
            }
            else
            {
                while (list->width - (int)ft_strlen(str) > 0)
                {
                    write(1, "0", 1);
                    list->width--;
                    list->bytes++;
                }
            }
    //        if (*str == '-' && list->width && list->accuracy)
    //            str++;
    //        if (*str == '0') //&& ft_strlen(str) == 1 &&
    //        {
    //            if (list->flag & FLAG_NULL)
    //                write(1, "0", 1);
    //            else
    //                write(1," ",1);
    //        }
    //        else
    //            write(1, &*str, ft_strlen(str));
            if (*str == '0' && ft_strlen(str) == 1 && list->flag & FLAG_DOT && list->width) //&& ft_strlen(str) == 1 && //!accuracy
            {
                if ((list->flag & FLAG_DOT) && accuracy)//&& !(list->width))
                    write(1, "0", 1);
                else
                    write(1," ",1);
            }
            else if (*str == '0' && !accuracy && list->flag & FLAG_DOT)
            {
                list->bytes--;
            }
            else
            {
                if (*str == '-' && accuracy == (int)ft_strlen(str))
                {
                    str++;
                    write(1, "-0", 2);
                }
                else if (*str == '-' && list->width < accuracy)
                {
                    str++;
                    list->bytes++;
                    write(1, "0", 1);
                }
                write(1, &*str, ft_strlen(str));
            }
        }
}
