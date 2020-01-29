#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include "tcp_connection.h"
#include "acceptor.h"
#include "event_loop.h"
#include "event_loop_thread_pool.h"

struct TCPserver {
    int port;
    struct event_loop *eventLoop;
    struct acceptor *acceptor;
    connection_completed_call_back connectionCompletedCallBack;
    message_call_back messageCallBack;
    write_completed_call_back writeCompletedCallBack;
    connection_closed_call_back connectionClosedCallBack;
    int threadNum;
    struct event_loop_thread_pool *threadPool;
    void * data; //for callback use: http_server
};

//准备监听套接字
struct TCPserver *
tcp_server_init(struct event_loop *eventLoop, struct acceptor *acceptor,
                connection_completed_call_back connectionCallBack,
                message_call_back messageCallBack,
                write_completed_call_back writeCompletedCallBack,
                connection_closed_call_back connectionClosedCallBack,
                int threadNum);

//开启监听
void tcp_server_start(struct TCPserver *tcpServer);

//设置callback数据
void tcp_server_set_data(struct TCPserver *tcpServer, void * data);

void make_nonblocking(int fd);

#endif
