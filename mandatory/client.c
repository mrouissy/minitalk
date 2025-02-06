#include "../headers/minitalk.h"

 int main(int ac, char **av)
 {
	int i;
	pid_t pid;

	if(ac != 3)
	{
		ft_putstr("Error:commande must be like that\n	./client pid message");
		return(1);
	}
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

