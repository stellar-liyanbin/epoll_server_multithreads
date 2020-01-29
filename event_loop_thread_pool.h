#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include "event_loop.h"
#include "event_loop_thread.h"

struct event_loop_thread_pool {
    //创建thread_pool的主线程
    struct event_loop *mainLoop;
    //是否已经启动
    int started;
    //线程数目
    int thread_number;
    //数组指针，指向创建的event_loop_thread数组
    struct event_loop_thread *eventLoopThreads;

    //表示在数组里的位置，用来决定选择哪个event_loop_thread服务
    int position;

};

struct event_loop_thread_pool *event_loop_thread_pool_new(struct event_loop *mainLoop, int threadNumber);

void event_loop_thread_pool_start(struct event_loop_thread_pool *);

struct event_loop *event_loop_thread_pool_get_loop(struct event_loop_thread_pool *);

#endif