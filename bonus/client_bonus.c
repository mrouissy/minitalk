#include "../headers/minitalk.h"

static void	msg()
{
	ft_printf("Message received by the server\n");
}
 int main(int ac, char **av)
 {
	int i;
	pid_t pid;

	if(ac != 3)
	{
		ft_putstr("Error:commande must be like that\n	./client pid message");
		return(1);
	}
	signal(SIGUSR1,&msg);
	i = 0;
	while(av[1][i])
	{
		if(!ft_isdigit(av[1][i]))
		{
			ft_putstr("Error:the pid is integer!!");
			return(1);
		}
		i++;
	}
	pid = ft_atoi(av[1]);
	sender(pid,av[2]);
	return 0;
 }

