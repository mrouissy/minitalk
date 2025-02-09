#include "utils.h"

void decrypt(int sig)
{
	static char byt;
	static int i;

	byt = byt << 1; // we shift to add new bit
	if(sig == SIGUSR1)
		byt++;
	i++;
	if(byt && i > 7)
	{
		write(1,&byt,1);
		byt = 0;
		i = 0;
	}
	else if (!byt && i > 7)
	{
		write(1,"\n",1);
		byt = 0;
		i = 0;
	}

}
void decrypt_bonus(int sig, siginfo_t *info,void *con)
{
	static char byt;
	static int i;

	(void)con;
	byt = byt << 1;
	if(sig == SIGUSR1)
		byt++;
	i++;
	if(byt && i > 7)
	{
		write(1,&byt,1);
		byt = 0;
		i = 0;
	}
	else if (!byt && i > 7)
	{
		write(1,"\n",1);
		byt = 0;
		i = 0;
		kill(info->si_pid,SIGUSR1);
	}

}
