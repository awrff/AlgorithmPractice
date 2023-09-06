#include "thread_pool.h"
#include <iostream>

int main(){
    std::cout << "start" << std::endl;
    MyThreadPool pool(5);
    for(int i=0; i<3; i++){
        pool.addTask([i](){
            std::cout << "thread " << i << std::endl; 
        });
    }
    std::this_thread::sleep_for(std::chrono::duration<double>(2));
}