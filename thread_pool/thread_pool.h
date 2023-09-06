#pragma once
#include <thread>
#include <assert.h>
#include <mutex>
#include <functional>
#include <queue>
#include <condition_variable>

class MyThreadPool{
    public:
        MyThreadPool(int threadCnt): threadCnt(threadCnt){
            assert(threadCnt > 0);
            for(int i=0; i<threadCnt; i++){
                std::thread worker([=](){
                    std::unique_lock<std::mutex> lck(mtx);
                    while(true){
                        if(closed) break;
                        if(!tasks.empty()){
                            auto task = std::move(tasks.front());
                            tasks.pop();
                            task();
                        }
                        else cond.wait(lck);
                    }
                });
                worker.detach();
            }
        }
        MyThreadPool() = default;
        MyThreadPool(MyThreadPool&&) = default;
        ~MyThreadPool(){
            {
                std::lock_guard<std::mutex> lck(mtx);
                closed = true;
            }
            cond.notify_all();
        }
        void addTask(std::function<void()> task){
            {
                std::lock_guard<std::mutex> lck(mtx);
                tasks.push(std::move(task));
            }
            cond.notify_one();
        }
    private:
        int threadCnt;
        bool closed = false;
        std::mutex mtx;
        std::condition_variable cond;
        std::queue<std::function<void()>> tasks;
};