#include <stdio.h>
#include <unistd.h>
#include "libft.h"

int main(void)
{

    pid_t pid;
    pid = getpid();
    ft_putnbr_fd((int)pid, 1);
    write(1, "\n", 1);
    printf("%i\n", (int)pid);

}