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
// ����������������������תʱ��Ƭ��������ռ�õ�CPUʱ�䣬���̻���Ҫ��CPUʱ�䣬���̵�״̬����ǰ����ָ��ȡ�

#endif // PUBLIC_HPP