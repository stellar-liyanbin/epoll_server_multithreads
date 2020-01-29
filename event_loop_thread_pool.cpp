#include <assert.h>
#include "utils.h"
#include "event_loop_thread_pool.h"

struct event_loop_thread_pool *event_loop_thread_pool_new(struct event_loop *mainLoop, int threadNumber) {

    struct event_loop_thread_pool *threadPool = (struct event_loop_thread_pool *)malloc(sizeof(struct event_loop_thread_pool));
    threadPool->mainLoop = mainLoop;
    threadPool->position = 0;
    threadPool->thread_number = threadNumber;
    threadPool->started = 0;
    threadPool->eventLoopThreads = NULL;
    return threadPool;
}

//一定是main thread发起
void event_loop_thread_pool_start(struct event_loop_thread_pool *threadPool) {
    assert(!threadPool->started);
    assertInSameThread(threadPool->mainLoop);

    threadPool->started = 1;

    if (threadPool->thread_number <= 0) {
        return;
    }

    threadPool->eventLoopThreads = (struct event_loop_thread *)malloc(threadPool->thread_number * sizeof(struct event_loop_thread));
    for (int i = 0; i < threadPool->thread_number; ++i) {
        event_loop_thread_init(&threadPool->eventLoopThreads[i], i);
        event_loop_thread_start(&threadPool->eventLoopThreads[i]);
    }
}

//一定是main thread中选择
struct event_loop *event_loop_thread_pool_get_loop(struct event_loop_thread_pool *threadPool) {
    assert(threadPool->started);
    assertInSameThread(threadPool->mainLoop);

    //优先选择当前主线程
    struct event_loop *selected = threadPool->mainLoop;

    //从线程池中按照顺序挑选出一个线程
    if (threadPool->thread_number > 0) {
        selected = threadPool->eventLoopThreads[threadPool->position].eventLoop;
        if (++threadPool->position >= threadPool->thread_number) {
            threadPool->position = 0;
        }
    }

    return selected;
}
