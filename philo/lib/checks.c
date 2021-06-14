#include "../includes/philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (1);
	else if (!s1 && !s2)
		return (0);
	while (*s1 == *s2++)
		if (*s1++ == 0)
			return (0);
	return (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
}

bool	check_int_overflow(char *str)
{
	char	*tmp;
	bool	res;

	tmp = ft_itoa(ft_atoi(str));
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		while (*str == '0' && ft_strlen(str) > 1)
			str++;
		if (*str != '0')
		{
			str--;
			*str = '-';
		}
	}
	else
		while (*str == '0' && ft_strlen(str) > 1)
			str++;
	res = ft_strcmp(str, tmp);
	free(tmp);
	return (res != 0);
}

bool	is_digits(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}
