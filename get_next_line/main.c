#include <stdio.h>
#include "libft.h"
#include "get_next_line.h"

int     main(int argc, char **argv)
{
    char *str;
    int retvalue;
    int i;
    int fd;

    if (argc == 1)
        return (0);
    i = 0;
    fd = 1;
    retvalue = 1;
    while (++i < argc)
    {
        fd = open(argv[i], O_RDONLY);
        while (retvalue)
        {
            retvalue = get_next_line(fd, &str);
            printf("fd = %d; retvalue = %d\nstring = %s\n\n", fd, retvalue, str);
        }
    }
    close(fd);
    return (0);
}