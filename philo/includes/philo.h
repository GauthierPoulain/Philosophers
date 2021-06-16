#ifndef PHILO_H
# define PHILO_H

# define _DEFAULT_SOURCE

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <time.h>
# include <sys/time.h>

# define	_DEFAULT			"\033[1;39m"
# define	_RED				"\033[1;31m"
# define	_GREEN				"\033[1;32m"
# define	_YELLOW				"\033[1;33m"
# define	_BLUE				"\033[1;34m"
# define	_MAGENTA			"\033[1;35m"
# define	_CYAN				"\033[1;36m"
# define	_LIGHTGRAY			"\033[1;37m"
# define	_DARKGRAY			"\033[1;90m"
# define	_LIGHTRED			"\033[1;91m"
# define	_LIGHTGREEN			"\033[1;92m"
# define	_LIGHTYELLOW		"\033[1;93m"
# define	_LIGHTBLUE			"\033[1;94m"
# define	_LIGHTMAGENTA		"\033[1;95m"
# define	_LIGHTCYAN			"\033[1;96m"
# define	_WHITE				"\033[1;97m"

# define	_END				"\033[1;0m"

# define	PRINT_SPAWN			0
# define	PRINT_COLORS		0

# define	MSG_SPAWN			1
# define	MSG_FORK			2
# define	MSG_EAT				3
# define	MSG_SLEEP			4
# define	MSG_THINK			5
# define	MSG_DIED			6

# define	ERR_ARGSNUMBER		1
# define	ERR_INVALIDARG		2
# define	ERR_MALLOC			3

typedef struct s_monitor
{
	pthread_t		pthread;
	struct s_philo	*philo;
}				t_monitor;

typedef struct s_philo
{
	t_monitor			monitor;
	int					id;
	pthread_t			pthread;
	bool				alive;
	long long			timestamp;
	int					nb_eat;
	long long			last_eat;
	struct s_manager	*manager;
	struct s_philo		*prev_philo;
	struct s_philo		*next_philo;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		*right_fork;
}				t_philo;

typedef struct s_manager
{
	bool			error;
	t_philo			**philo;
	int				nb_philo;
	int				nb_forks;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				nb_eat;
	bool			die;
	pthread_t		unlocker;	
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_print;
}				t_manager;

int			ft_strcmp(const char *s1, const char *s2);
bool		check_int_overflow(char *str);
bool		is_digits(char *str);

size_t		ft_strlen(char *str);
size_t		ft_nblen(long long nb);

void		ft_bzero(void *s, size_t n);

long long	ft_atoi(const char *str);
char		*ft_itoa(long long n);

void		ft_putchar(int fd, char c);
void		ft_putstr(int fd, char *str);
void		ft_putcolor(int fd, char *str, char *color);
void		ft_putnbr(int fd, long long nb);

void		set_error(int code, t_manager *manager);
void		close_philo(t_manager *manager);

void		init(t_manager *manager, int argc, char *argv[]);

void		*philo_monitor(void *philo_raw);

void		philo_create(t_manager *manager, int id);
void		philo_spawn(t_manager *manager);

void		*philo_main(void *philo_raw);

void		philo_log(t_philo *philo, int type);

long long	get_time_ms(void);

#endif
