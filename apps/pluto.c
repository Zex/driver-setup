/**
 * Author: <Zex Li AT yahoo.com>
 */

#include <sys/ioctl.h>
#include <fcntl.h>
//#include <syslog.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    int pluto_fd = open("/dev/pluto", O_RDWR);

    if (0 > pluto_fd)
    {
       printf("Open pluto failed\n"); 
       return 0;
    }

    ioctl(pluto_fd, 3, 97123);

    close(pluto_fd);

    return 0;
}
