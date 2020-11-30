#include "ft_printf.h"
#include "parser/ft_parser.h"

void    ft_print_char (char c, s_cn *list)
{
    char chr = va_arg(list->v_list, int);
    write(1, &chr, 1);
}
