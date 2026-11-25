#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void print_file(const char *filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
}

int main(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        print_file(av[i]);
    }
    return 0;
}