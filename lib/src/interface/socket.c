#include <unistd.h>
#include <sys/socket.h>

#include "interface/socket.h"

ssize_t write_s(int fd, const char *buf, size_t count) {
    ssize_t total_bytes = 0;
    ssize_t result;
    while (total_bytes < count) {
        result = write(fd, buf, count);
        if (result == -1) { // Error
            break;
        } else {
            total_bytes += result;
        }
    }
    return total_bytes;
}

ssize_t read_s(int fd, char *buf, size_t count) {
    ssize_t total_bytes = 0;
    ssize_t result;
    while (total_bytes < count) {
        result = read(fd, buf + total_bytes, count - total_bytes);
        if (result == 0) {  // EOF
            break;
        } else if (result == -1) {  // Error
            break;
        } else {
            total_bytes += result;
        }
    }
    return total_bytes;
}

ssize_t send_s(int sockfd, const char *buf, size_t len, int flags) {
    ssize_t total_bytes = 0;
    ssize_t result;
    while (total_bytes < len) {
        result = send(sockfd, buf + total_bytes, len - total_bytes, flags);
        if (result == -1) { // Error
            break;
        } else {
            total_bytes += result;
        }
    }
    return total_bytes;
}

ssize_t recv_s(int sockfd, char *buf, size_t len, int flags) {
    ssize_t total_bytes = 0;
    ssize_t result;
    while (total_bytes < len) {
        result = recv(sockfd, buf, len, flags);
        if (result == -1) { // Error
            break;
        }
        /* else if (result == 0) {   // EOF
            break;
        } */
        else {
            total_bytes += result;
        }
    }
    return total_bytes;
}