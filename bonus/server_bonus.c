#include "../headers/minitalk.h"



int main(void)
{
	struct sigaction sig;

	ft_putstr("porcess id :");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sig.sa_sigaction = decrypt_bonus;
	sig.sa_flags = SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while(1)
	{
	}
}

