#include "libft.h"
#include <math.h>

void    if_valid(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    while (*str != '.' && *str != '\0' && *str != '\n')
    {
        if (!ft_isdigit(*str))
            ft_error(1, "parser", "invalid input");
        str++;
    }
    if (*str == '.')
        str++;
    while (*str != '\0' && *str != '\n')
    {
        if (!ft_isdigit(*str))
            ft_error(1, "parser", "invalid input");
        str++;
    }
}

float ft_atof(char *str)
{
	float	integer;
	float	decimal;
	float	sign;
	int		i;

	integer = 0.0;
	decimal = 0.0;
	sign = 1.0;
    if_valid(str);
	if (*str == '+' || *str == '-')
    {
		if (*str++ == '-')
			sign = -1.0;
    }
	while (ft_isdigit(*str))
		integer = integer * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			decimal += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (integer + decimal));
}
