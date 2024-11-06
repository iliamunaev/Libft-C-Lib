/*
 * Outputs the character ’c’ to the given file descriptor.
 * Return: None.
*/

#include "libft.h"
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}