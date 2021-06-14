#include "../includes/philo.h"

void	print(t_philo *philo, int type)
{
	if (type == PRINT_SPAWN && !PRINT_SPAWN)
		return ;
	pthread_mutex_lock(&philo->manager->mutex_print);
	ft_putnbr(STDOUT_FILENO, get_time_ms() - philo->timestamp);
	ft_putchar(STDOUT_FILENO, ' ');
	ft_putnbr(STDOUT_FILENO, philo->id);
	if (type == MSG_SPAWN)
		ft_putcolor(STDOUT_FILENO, " has spawn\n", _GREEN);
	else if (type == MSG_FORK)
		ft_putcolor(STDOUT_FILENO, " has taken a fork\n", _YELLOW);
	else if (type == MSG_EAT)
		ft_putcolor(STDOUT_FILENO, " is eating\n", _YELLOW);
	else if (type == MSG_SPAWN)
		ft_putcolor(STDOUT_FILENO, " is sleeping\n", _MAGENTA);
	else if (type == MSG_THINK)
		ft_putcolor(STDOUT_FILENO, " is thinking\n", _GREEN);
	else if (type == MSG_DIED)
		ft_putcolor(STDOUT_FILENO, " died\n", _RED);
	else
	{
		ft_putcolor(STDOUT_FILENO, "undefined type : ", _RED);
		ft_putnbr(STDOUT_FILENO, type);
		ft_putchar(STDOUT_FILENO, '\n');
	}
	pthread_mutex_unlock(&philo->manager->mutex_print);
}