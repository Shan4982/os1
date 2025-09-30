#pragma once
#include"public.hpp"
using namespace std;
class queue_list{
private:
    PCB *now;
    PCB *end;
    int timePiece = 5;
public:
    queue_list();
    void addPCB(PCB *p);
    bool deletePCB();
    bool if_empty();
    PCB* get_now();
};