#include "../ft_printf.h"
#include "../parser/ft_parser.h"
#include "../libft/libft.h"

void    ft_print_u(s_cn *list)
{
    char *str;
    str = ft_itoa(va_arg(list->v_list, int));
    write(1, 123, 3);
    /*
     *   unsigned int a = 0
     *   a = (unsigned int)-1234;
     *   printf("%u", a);
     */
}