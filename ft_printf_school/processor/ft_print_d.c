#include "../ft_printf.h"
#include "../parser/ft_parser.h"
#include "../libft/libft.h"

void    ft_print_d(s_cn *list)
{
    char    *str;
    int accuracy;
    int flag;

    str = ft_itoa(va_arg(list->v_list, int));
    if((list->flag & FLAG_MINUS))
    {
        if (*str == '-' && (list->flag & FLAG_MINUS))
        {
            list->width--;
            str++;
            write(1, "-", 1);
            list->bytes++;
            while (list->accuracy > ft_strlen(str))
            {
                write(1, "0", 1);
                list->accuracy--;
                list->bytes++;
                list->width--;
            }
        }
        while (list->accuracy > ft_strlen(str))
        {
            write(1, "0", 1);
            list->accuracy--;
            list->bytes++;
            list->width--;
        }
        write(1, &*str, ft_strlen(str));
        list->bytes += ft_strlen(str);
        while (list->width - list->accuracy > 0 && list->width > ft_strlen(str))
        {
            list->bytes++;
            list->width--;
            write(1, " ", 1);
        }
    }
    else
    {
        accuracy = list->accuracy;
        flag = 0;
        list->bytes += ft_strlen(str);
        if (*str == '-' && !(list->flag & FLAG_MINUS))
        {
            list->width--;
            str++;
            flag = 1;
        }
        while (list->width - list->accuracy > 0  && list->width > ft_strlen(str))
        {
            list->bytes++;
            list->width--;
            write(1, " ", 1);
        }
        if (flag == 1)
            write(1, "-", 1);
        if (list->flag & FLAG_DOT)
        {
            while (list->accuracy > ft_strlen(str))
            {
                write(1, "0", 1);
                list->accuracy--;
                list->bytes++;
            }
        }
        if (*str == '0' && !accuracy) //&& ft_strlen(str) == 1 &&
            write(1," ",1);
        else
            write(1, &*str, ft_strlen(str));
    }
}
