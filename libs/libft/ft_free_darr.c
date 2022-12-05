#include "libft.h"

void    ft_free_darr(char **darr)
{
    int i;

    i = 0;
	while(darr[i])
		i++;
    while (i >= 0)
    {
        free (darr[i]);
        i--;
    }
    free(darr);
}