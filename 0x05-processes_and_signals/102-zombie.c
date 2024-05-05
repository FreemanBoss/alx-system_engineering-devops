#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * infinite_while - a function to put the zombie function in infinite loop.
 *
 * Return: 0
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 *
 * main - A program that creates 5 zombie processes
 *
 * Return: 0
 */

int main(void)
{
	pid_t ZOMBIE_PID;
	int i;
	int process_num = 5;

	for (i = 0; i < process_num; i++)
	{
		ZOMBIE_PID = fork();
		if (ZOMBIE_PID == -1)
		{
			return (-1);
		}
		else if (ZOMBIE_PID > 0)
		{
			printf("Zombie process created, PID: %d\n", ZOMBIE_PID);
			sleep(2);
		}
		else 
		{
			exit(0);
		}
	}
	infinite_while();
	return (0);
}
