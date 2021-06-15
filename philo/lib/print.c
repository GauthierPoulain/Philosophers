#include "../includes/philo.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}

void	ft_putcolor(int fd, char *str, char *color)
{
	if (PRINT_COLORS)
		ft_putstr(fd, color);
	ft_putstr(fd, str);
	if (PRINT_COLORS)
		ft_putstr(fd, _END);
}

static void	ft_printnbr(int fd, int nb)
{
	char	cast;

	cast = nb + '0';
	write(fd, &cast, 1);
}

void	ft_putnbr(int fd, long long nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(fd, nb / 10);
		ft_printnbr(fd, nb % 10);
	}
	else
		ft_printnbr(fd, nb % 10);
}
