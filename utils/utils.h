

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

//printf
int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_unsigned(unsigned int n);
int	ft_hexa(unsigned int n, char format);
int	ft_printad(void *p);

//libft
int	ft_atoi(const	char	*str);
int	ft_isdigit(int i);

//minitalk utils
void decrypt(int sig);
void sender(pid_t pid, char *msg);

void decrypt_bonus(int sig, siginfo_t *info,void *con);
void sender_bonus(pid_t pid, char *msg);
