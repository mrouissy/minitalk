#include "../headers/minitalk.h"

int main(void)
{

	ft_putstr("porcess id :");
	ft_putnbr(getpid());
	ft_putstr("\n");
	signal(SIGUSR1,&decrypt);
	signal(SIGUSR2,&decrypt);
	while(1)
	{
	}
}

