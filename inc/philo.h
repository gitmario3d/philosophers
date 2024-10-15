/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:00:18 by malena-b          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:18 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>
#include <sys/time.h>
#include <ctype.h>

typedef struct s_info		t_info;
typedef struct s_philo		t_philo;
typedef struct s_fork		t_fork;

typedef	enum	s_mutex_code
{
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
	JOIN,
	CREATE,
}				t_m_code;

typedef enum e_lock
{
	THINK,
	DEATH,
	EAT,
	SLEEP,
	DIED,
	MEALS,
	FORKS,
	L_FORK,
	R_FORK,
}			t_lock;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}				t_fork;

typedef struct s_info
{
	int				philo_numbers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			start_time;
	int				total_meals;
	int				full;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meat_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
	t_fork			*forks;
	pthread_t		monitor;
	int				dead_flag;
	int				error_check;
}				t_info;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	bool			full;
	t_fork			*l_fork;
	t_fork			*r_fork;
	int				last_meat;
	int				meats;
	int				*dead_flag;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meat_lock;
	pthread_mutex_t	*write_lock;
	t_info			*info;
	
}				t_philo;



int		ft_atoi(const char *str);
t_info	*ft_init_info(t_info *info, char **argv);
void	ft_init_philos(t_info *info);
int		ft_error_msg(t_info *info, char *error_msg);
void	ft_thread(t_m_code code, void *(*func)(void *), void *aux, int monitor);
int		ft_check_philo_numbers(t_info *info);
void	ft_clean_mutex(t_info *info);
void	ft_free_all(t_info *info);
int		ft_get_time(void);
int		ft_get_mutex_int(t_info *info, t_philo *philo, int on_off);
void	*ft_dinner(void *aux);
void	ft_report(t_philo *philo, t_lock action);
void	ft_forks_mutex(t_philo *philo, int option);
void	ft_monitor_mutex(t_info *info, t_lock m_code, t_philo *philo, int opt);
void	ft_clean_mutex(t_info *info);
void	ft_init_thread(t_info *info, int i);
void	ft_mutex_actions(t_info	*info, t_m_code m_code, pthread_mutex_t *mutex);
void	*ft_monitor(void *aux);
void	ft_sleep(int sleep_time);
