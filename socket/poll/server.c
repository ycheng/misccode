
#define _GNU_SOURCE

#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/poll.h>
#include <string.h>
#include <netinet/tcp.h>




int main( int argc, char *argv[] )
{
    int sockfd, newsockfd, portno, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int  n;

    int on;
    int rc;

    int timeout;
    struct pollfd fds[200];
    int    nfds = 1;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
    {
        perror("ERROR opening socket");
        exit(1);
    }

    on = 1;
    rc = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
                  (char *)&on, sizeof(on));
    if (rc < 0)
    {
        perror("setsockopt() failed");
        close(sockfd);
        exit(-1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = 5001;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
 
    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
                          sizeof(serv_addr)) < 0)
    {
         perror("ERROR on binding");
         exit(1);
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection
    */
    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, 
                                &clilen);
    if (newsockfd < 0) 
    {
        perror("ERROR on accept");
        exit(1);
    }


    {
      int optval = 1;
      socklen_t optlen = sizeof(optval);

      setsockopt(newsockfd, SOL_SOCKET, SO_KEEPALIVE, &optval, optlen);
      optval = 2;
      setsockopt(newsockfd, SOL_TCP, TCP_KEEPCNT, &optval, optlen);
      setsockopt(newsockfd, SOL_TCP, TCP_KEEPIDLE, &optval, optlen);
      setsockopt(newsockfd, SOL_TCP, TCP_KEEPINTVL, &optval, optlen);
    }






    while (-1) {
        memset(fds, 0 , sizeof(fds));
        fds[0].fd = newsockfd;
        fds[0].events = POLLIN | POLLRDHUP;
        timeout = (3 * 60 * 1000);
        nfds = 1;

        printf("Waiting on poll()...\n");
        rc = poll(fds, nfds, timeout);
        if (rc < 0)
        {
            perror("  poll() failed");
            break;
        }
        /***********************************************************/
        /* Check to see if the 3 minute time out expired.          */
        /***********************************************************/
        if (rc == 0) {
            printf("  poll() timed out.  End program.\n");
            break;
        }
        if(fds[0].revents == 0)
            continue;

        if(fds[0].revents == POLLIN)
        {
          /* If connection is established then start communicating */
          bzero(buffer,256);
          n = read( newsockfd,buffer,255 );
          if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
          }
          printf("Here is the message: %s\n",buffer);
        } else if(fds[0].revents == POLLRDHUP) {
          printf("revents POLLRDHUP %x\n", fds[0].revents);
          exit(1);
        } else {
          printf("revents %x\n", fds[0].revents);
          exit(1);
        }
        
    }

    /* Write a response to the client */
    n = write(newsockfd,"I got your message",18);
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(1);
    }
    return 0; 
}
