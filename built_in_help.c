#include "main.h"

/**
* countArgs - count the number of arguments
* @args: input array of strings
* Return: number of strings
*/
int countArgs(char **args)
{
	register int index = 0;

	while (args[index])
		index++;
	return (index);
}

/**
* _atoi - change string to an integer
* @str: input string
* Return: -1 if it's not a valid number, else the converted number
*/
int _atoi(char *str)
{
	register int index = 0;
	unsigned long num = 0;

	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			num = num * 10 + str[index] - '0';
		else
			return (-1);
		index++;
	}
	if (num > INT_MAX)
	{
		return (-1);
	}
	return (num);
}
