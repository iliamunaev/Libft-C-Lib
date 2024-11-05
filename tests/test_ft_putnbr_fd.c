#include "../test42lib/test42lib.h"
#include "tests.h"

// Helper
void	putnbr_fd(int fd)
{
    ft_putnbr_fd(0, fd);
    ft_putnbr_fd(777, fd);
	ft_putnbr_fd(42, fd);
}

void	test_ft_putnbr_fd(void)
{
    FD_OUTPUT_TO_FILE(putnbr_fd, "ft_putnbr_fd_test.txt");
}