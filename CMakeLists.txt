cmake_minimum_required(VERSION 3.17)
project(ft_printf_school C)

set(CMAKE_C_STANDARD 99)

add_executable( ft_printf_school
        main.c
        ./libft/ft_atoi.c
        ./libft/ft_strchr.c
        ./parser/ft_struct_init.c
        ./libft.a
        )
