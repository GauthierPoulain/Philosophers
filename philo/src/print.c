#include "../includes/philo.h"

void	philo_log(t_philo *philo, int type)
{
	if ((type == PRINT_SPAWN && !PRINT_SPAWN) || !philo->alive)
		return ;
	pthread_mutex_lock(&philo->manager->mutex_print);
	if (philo->manager->die)
		return ((void)pthread_mutex_unlock(&philo->manager->mutex_print));
	ft_putnbr(STDOUT_FILENO, get_time_ms() - philo->timestamp);
	ft_putchar(STDOUT_FILENO, ' ');
	ft_putnbr(STDOUT_FILENO, philo->id);
	if (type == MSG_SPAWN)
		ft_putcolor(STDOUT_FILENO, " has spawn\n", _GREEN);
	else if (type == MSG_FORK)
		ft_putcolor(STDOUT_FILENO, " has taken a fork\n", _CYAN);
	else if (type == MSG_EAT)
		ft_putcolor(STDOUT_FILENO, " is eating\n", _YELLOW);
	else if (type == MSG_SLEEP)
		ft_putcolor(STDOUT_FILENO, " is sleeping\n", _MAGENTA);
	else if (type == MSG_THINK)
		ft_putcolor(STDOUT_FILENO, " is thinking\n", _GREEN);
	else if (type == MSG_DIED)
		ft_putcolor(STDOUT_FILENO, " died\n", _RED);
	else
		ft_putcolor(STDOUT_FILENO, "undefined type\n", _RED);
	if (type != MSG_DIED)
		pthread_mutex_unlock(&philo->manager->mutex_print);
}
