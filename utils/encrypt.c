#include "utils.h"

void sender(pid_t pid, char *msg)
{
	size_t i;
	int bit;

	i = 0;
	while(msg[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if((msg[i] >> bit) & 1)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			usleep(10);
			bit--;
		}
		i++;
	}
}
void sender_bonus(pid_t pid, char *msg)
{
	size_t i;
	int bit;

	i = 0;
	while(msg[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if((msg[i] >> bit) & 1)
				kill(pid,SIGUSR1);
			else
				kill(pid,SIGUSR2);
			usleep(10);
			bit--;
		}
		i++;
	}
}
