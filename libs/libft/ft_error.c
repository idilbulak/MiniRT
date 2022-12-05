#include "libft.h"

void    ft_error(int i, char *str1, char *str2)
{
    printf("Error_%s :\t%s\n", str1, str2);
    exit (i);
}