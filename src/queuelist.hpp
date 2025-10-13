#pragma once
#include"public.hpp"
using namespace std;
class queue_list{
private:
    PCB *now;
    PCB *end;
    
    int where;
   
public: 
    int timePiece;
    int now_piece;
    queue_list();
    ~queue_list( );
    void addPCB(PCB *p);
    bool if_empty();
    PCB* get_now();
    void set_timePiece(int timePiece);
    void set_where(int where);
    int get_dress();
    bool updata_ifmove();
    void deletePCB();
    void movePCB();
    bool if_isrunning();
};


class all_queue
{
private:
    void move_PCB(PCB *p,int where);
public:
    queue_list group1;
    queue_list group2;
    queue_list group3;
    all_queue();
    void addPCB(PCB *p);
    bool if_empty();
    void updata();
    void clear(int n = 0);
};

