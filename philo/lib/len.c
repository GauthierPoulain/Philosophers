#include "../includes/philo.h"

size_t	ft_strlen(char *str)
{
	char	*s;

	if (!str)
		return (0);
	s = str;
	while (*str)
		++str;
	return (str - s);
}

size_t	ft_nblen(long long nb)
{
	size_t	len;

	len = 0;
	if (!nb)
		return (1);
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
