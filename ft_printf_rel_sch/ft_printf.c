#include "ft_parser.h"
#include "ft_printf.h"
//#include "./include/ft_processor.h"

int ft_printf(char *format, ...)
{
    s_cn conv;
    int ret;
    va_start(conv.v_list, format);

    ret = ft_parser(format, &conv);

    va_end(conv.v_list);
    return (ret);
}
