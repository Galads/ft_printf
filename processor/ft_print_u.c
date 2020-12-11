#include "../ft_printf.h"
#include "../libft/libft.h"
#include "../parser/ft_parser.h"

void    ft_print_u(s_cn *list, int base)
{
    char    *str;
    int     accuracy;
    int     flag;

    if (base == 17)
    {
        flag = 1;//111
        base--;
    }
    str = ft_itoa_base_xu(va_arg(list->v_list, unsigned int), base);
    if (flag == 1)//111
    {
        flag = 0;
        while (str[flag])
        {
            str[flag] = (char)ft_tolower(str[flag]);
            flag++;
        }
    }
    if((list->flag & FLAG_MINUS))
    {
        if (*str == '-' && (list->flag & FLAG_MINUS))
        {
            list->width--;
            str++;
            //write(1, "-", 1);
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
            if (list->flag & FLAG_NULL)
            {
                write(1, "0", 1);
                continue;
            }
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
        if (*str == '0' && !accuracy)                               //&& ft_strlen(str) == 1 &&
             {
                 if (list->flag & FLAG_NULL)
                     write(1, "0", 1);
                 else
                     write(1," ",1);
             }
        else
            write(1, &*str, ft_strlen(str));
    }
    //ft_putstr_fd(str, 1);
}