#ifndef PUBLIC_HPP
#define PUBLIC_HPP

#include<string>
#include<iostream>
using namespace std;
enum status_{
    waiting,processing,stop
};

class PCB{
    public:
    PCB(string namee,int timee) :name(namee),sum_time(timee){
        need_time = sum_time;
        next = nullptr;
    };
    PCB(){};
    string name;
    int priority;
    int sum_time;
    int had_time;
    int need_time;
    status_ status;
    int where;
    PCB* next; 
};
// 进程名，进程优先数，轮转时间片，进程已占用的CPU时间，进程还需要的CPU时间，进程的状态，当前队列指针等。

#endif // PUBLIC_HPP