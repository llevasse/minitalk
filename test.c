#include "includes/minitalk.h"

int	main(void)
{
	write(1, "\033[1;31m", 8);
	write(1, "hi", 2);
	write(1, "\033[0m\n", 6);
}