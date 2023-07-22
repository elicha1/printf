#include "main.h"
#include <unistd.h>

/**
 * _putcharacter - writes the character c to stdout
 * @c: The character to print
 * Return: 1 on success, while -1 on failure
 * Description: Helps to call write as little as possible
 * by using a local buffer of 1024
 */
int _putcharacter(char c)
{
	static char buf[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buf, i);
		i = 0;
	}
	if (c != -1)
	{
		buf[i] = c;
		i++;
	}
	return (1);
}
