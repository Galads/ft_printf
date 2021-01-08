
#include "ft_printf.h"
#include "ft_parser.h"

void    ft_print_helper(s_cn *list, char **str, int *i)
{
    write(1, &(*str)[(*i)++], 1);
    list->bytes++;
}

void    ft_print_second_helper(s_cn *list)
{
    list->width--;
    list->bytes++;
    write(1, " ", 1);
}
