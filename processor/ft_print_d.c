#include "../ft_printf.h"
#include "../parser/ft_parser.h"
#include "../libft/libft.h"

void    ft_print_d(s_cn *list)
{
    char    *str;

    int width;
    int len_str;
    str = ft_itoa(va_arg(list->v_list, int));
    len_str = ft_strlen(str);
    list->width -= len_str;

    if((list->flag & FLAG_MINUS))
    {
        list->bytes += ft_strlen(str);
        write(1, &*str, list->bytes);
        while (list->width--)
        {
            list->bytes++;
            write(1, " ", 1);
        }
    }
    else
    {
        if (list->flag & FLAG_DOT)
        {
            list->accuracy;

        }
        list->bytes += ft_strlen(str);
        width = list->bytes;
        while ((list->width--) > 0)
        {
            list->bytes++;
            write(1, " ", 1);
        }
        write(1, &*str, width);
    }

}
