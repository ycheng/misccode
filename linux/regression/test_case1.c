#define __USE_GNU 1
#define _GNU_SOURCE 1


#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

int main()
{
    enum { server, client, size };
    int socket_fd[size];
    int const opt = 1;

    assert(socketpair(AF_LOCAL, SOCK_STREAM, 0, socket_fd) == 0);

    char const msg[] = "A random message";
    send(socket_fd[client], msg, sizeof msg, MSG_DONTWAIT | MSG_NOSIGNAL);

    assert(setsockopt(socket_fd[server], SOL_SOCKET, SO_PASSCRED, &opt, sizeof(opt)) != -1);

    union {
        struct cmsghdr cmh;
        char control[CMSG_SPACE(sizeof(struct ucred))];
    } control_un;

    control_un.cmh.cmsg_len = CMSG_LEN(sizeof(struct ucred));
    control_un.cmh.cmsg_level = SOL_SOCKET;
    control_un.cmh.cmsg_type = SCM_CREDENTIALS;

    struct msghdr msgh;
    msgh.msg_name = NULL;
    msgh.msg_namelen = 0;
    msgh.msg_iov = NULL;
    msgh.msg_iovlen = 0;
    msgh.msg_control = control_un.control;
    msgh.msg_controllen = sizeof(control_un.control);

    errno = 0;

    if (recvmsg(socket_fd[server], &msgh, MSG_PEEK) == -1)
    {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("Success!\n");
        exit(EXIT_SUCCESS);
    }
}
