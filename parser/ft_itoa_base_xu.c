//
// Created by Belwas Rice on 12/8/20.
//
#include "ft_parser.h"
#include "../libft/libft.h"

static	size_t	ft_size(unsigned int new, int base)
{
    int	sum;

    sum = 0;
    while (new / base)
    {
        new /= base;
        sum++;
    }
    sum++;
    return (sum);
}

static	char	*ft_while(char *str, unsigned int sum, unsigned int new, int base)
{
    while (sum > 0)
    {
        str[sum-- - 1] = new % base + (new % base > 9 ? '7' : '0');
        new /= base;
    }
    return (str);
}

char			*ft_itoa_base_xu(unsigned int n, int base) //rewrite
{
    char			*str;
    unsigned int 	sum;
    unsigned int 	new;

    new = n;
    sum = ft_size(new, base);
    if (!(str = ft_calloc(sizeof(char), (sum) + 2)))
        return (NULL);
    str = ft_while(str, sum, new, base);
    return (str);
}