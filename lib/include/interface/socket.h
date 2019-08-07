/* Copyright (C) 2019 rapsealk */

#ifndef __INTERFACE_SOCKET_H__
#define __INTERFACE_SOCKET_H__

#include <sys/types.h>  // ssize_t: signed int

ssize_t write_s(int fd, const char *buf, size_t count);
ssize_t read_s(int fd, char *buf, size_t count);

ssize_t send_s(int sockfd, const char *buf, size_t len, int flags);
ssize_t recv_s(int sockfd, char *buf, size_t len, int flags);

#endif  // __INTERFACE_SOCKET_H__