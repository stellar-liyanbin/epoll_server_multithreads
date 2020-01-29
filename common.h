#ifndef __USER_COMMON_H_
#define __USER_COMMON_H_

#include    <sys/types.h>    /* basic system data types */
#include    <sys/socket.h>    /* basic socket definitions */
#include    <sys/time.h>    /* timeval{} for select() */
#include    <time.h>        /* timespec{} for pselect() */
#include    <netinet/in.h>    /* sockaddr_in{} and other Internet defns */
#include    <arpa/inet.h>    /* inet(3) functions */
#include    <errno.h>
#include    <fcntl.h>        /* for nonblocking */
#include    <netdb.h>
#include    <signal.h>
#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <sys/stat.h>    /* for S_xxx file mode constants */
#include    <sys/uio.h>        /* for iovec{} and readv/writev */
#include    <unistd.h>
#include    <sys/wait.h>
#include    <sys/un.h>        /* for Unix domain sockets */

#include    <sys/select.h>    /* for convenience */
#include    <sys/sysctl.h>
#include    <poll.h>        /* for convenience */
#include    <strings.h>        /* for convenience */
#include    <sys/ioctl.h>
#include    <pthread.h>


#define EPOLL_ENABLE 1 /* epoll 从内核2.6开始完善支持，此处假设均支持 */

#ifdef EPOLL_ENABLE
#include    <sys/epoll.h>
#endif

#define     SERV_PORT   12345
#define     MAXLINE     4096
#define     LISTENQ     1024


#endif /* __USER_COMMON_H_ */
