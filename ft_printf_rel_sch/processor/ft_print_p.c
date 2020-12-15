#include "../ft_printf.h"
#include "../libft/libft.h"

static void ft_print(s_cn *list, char *str)
{
    while (list->width > 0 && list->width > ft_strlen(str))
    {
        list->bytes++;
        list->width--;
        write(1, " ", 1);
    }
}

void    ft_print_p(s_cn *list)
{
    char    *str;

    str = ft_itoa_base_ull(va_arg(list->v_list, unsigned long long), 16);
    list->bytes += ft_strlen(str);
    if (list->width < 0)
    {
        list->width *= -1;
        list->flag |= FLAG_MINUS;
    }
    if((list->flag & FLAG_MINUS))
    {
        write(1, &*str, list->bytes);
        ft_print(list, str);
    }
    else
    {
        ft_print(list, str);
        write(1, &*str, ft_strlen(str));
    }
}