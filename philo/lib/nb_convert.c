#include "../includes/philo.h"

static int	ft_atoi_calcsign(int pos, int neg)
{
	if ((!pos && !neg) || (pos == 1 && !neg))
		return (1);
	else if (!pos && neg == 1)
		return (-1);
	else
		return (0);
}

long long	ft_atoi(const char *str)
{
	char		*tstr;
	int			pos;
	int			neg;
	long long	res;

	if (!str)
		return (0);
	tstr = (char *)str;
	res = 0;
	pos = 0;
	neg = 0;
	while ((*tstr >= 9 && *tstr <= 13) || *tstr == ' ')
		tstr++;
	while (*tstr == '+' || *tstr == '-')
	{
		if (*tstr++ == '+')
			pos++;
		else
			neg++;
	}
	while (*tstr >= '0' && *tstr <= '9')
		res = (res * 10) + (*tstr++ - '0');
	return (res * ft_atoi_calcsign(pos, neg));
}

char	*ft_itoa(long long n)
{
	char		*res;
	long long	count;
	long long	i;
	long long	tmp;

	tmp = n;
	count = ft_nblen(n);
	if (tmp < 0 || count == 0)
		count++;
	res = malloc(sizeof(char) * (count + 1));
	ft_bzero(res, count + 1);
	i = 0;
	if (tmp < 0)
	{
		tmp *= -1;
		res[i++] = '-';
	}
	while (count > i)
	{
		res[--count] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (res);
}
