#include "./parser/ft_parser.h"

int ft_printf(char *format, ...)
{
    s_cn conv;
    va_start(conv.v_list, format);

    ft_parser(format, &conv);

    va_end(conv.v_list);
    return (0);
}