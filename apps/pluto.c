/**
 *
 */

#include <sys/ioctl.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int pluto_fd = open("/dev/pluto", O_RDWR);

    ioctl(pluto_fd, 3, 97123);

    close(pluto_fd);

    return 0;
}
