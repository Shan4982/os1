#include"queuelist.hpp"


queue_list::queue_list():now(nullptr),end(nullptr)
{
}


void queue_list::addPCB(PCB *p)
    {
 
       if(now==nullptr)
       {
        now = p;
        end = now;
        end->next = nullptr;
        p->status = waiting;
       }
       else
       {
        end->next = p;
        end = p;
        end->next = nullptr;
       }
    }


bool queue_list::if_empty()
    {
        if(now==nullptr)
        {
        return 1;
        }
        else
        return false;
    }




    PCB* queue_list::get_now()
    {
        return now;
    }

    void  queue_list::set_timePiece(int timePiece)
    {

        this->timePiece = timePiece;
    }

    int queue_list::get_dress()
     {
        return now->where;
     }




queue_list::~queue_list()
{
 
    while(now!=nullptr)
    {
        PCB *p = now;
        now = now->next;
        delete p;
    }
}

void queue_list::set_where(int wheree)
{

    this->where = wheree;
}

bool queue_list::updata_ifmove()
{

    if(now==nullptr)
    {
        cerr<<"now is not exits"<<endl;
        return 0;
    }
    else
    {
        if(now_piece<=0)
        {
            now_piece = timePiece;
            now->status = waiting;
            return true;
        }
        now->status = processing;
        now->had_time++;
        now->need_time--;
        now_piece--;
        if(now->need_time<=0)
        {
            now->need_time = 0;
            now->status = stop;
            now_piece = timePiece;
            deletePCB();
            return false;
        }
        return false;
    }
}

void queue_list::deletePCB()
{

    if(now==nullptr)
    {
        return;
    }
    else
    {
        PCB *p = now;
        now = now->next;
        delete p;
    }
}

void queue_list::movePCB()
{

    if(now==nullptr)
    {
        cerr<<"now is not exits"<<endl;
        return;
    }
    else
    {
        now = now->next;
    }
}

bool queue_list::if_isrunning()
{
    if(now==nullptr)
    {
        return false;
    }
    else if(now->status==processing)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//////////////////////////////////////////////////////////////////////////////


all_queue::all_queue()
{
    group1.set_where(1);
    group2.set_where(2);
    group3.set_where(3);
    group1.set_timePiece(5);
    group2.set_timePiece(6);
    group3.set_timePiece(8);
    group1.now_piece = group1.timePiece ;
    group2.now_piece = group2.timePiece ;
    group3.now_piece = group3.timePiece ;
};

void all_queue::addPCB(PCB *p)
{   
    group1.addPCB(p);
}

bool all_queue::if_empty()
{
    if(group1.if_empty()&&group2.if_empty()&&group3.if_empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


void all_queue::move_PCB(PCB *p,int where)
{
    if(where==2)
    {
        all_queue::group2.addPCB(p);
    }
    else if(where==3)
    {
        all_queue::group3.addPCB(p);
    }
    else
    {
        cerr<<"error"<<endl;
    }
}


void all_queue::updata()
{
    if(!group1.if_empty()&&!group2.if_isrunning()&&!group3.if_isrunning())
    {
        if(group1.updata_ifmove())
        {   
            PCB * temp = group1.get_now();
            group1.movePCB();
            move_PCB(temp,2);
        }
    }
    else if(!group2.if_empty()&&!group3.if_isrunning())
    {
        if(group2.updata_ifmove())
        {   
            PCB * temp = group2.get_now();
            group2.movePCB();
            move_PCB(temp,3);
        }
    }
    else if(!group3.if_empty())
    {
        group3.updata_ifmove();
    }
}

void all_queue::clear(int n)
{
    if(n==1||n==0)
    {
    if(group1.if_empty())
    {
        return;
    }
    else
    {
        while(!group1.if_empty())
        {
            group1.deletePCB();
        }
    }
    }

    if(n==2||n==0)
    {
    if(group2.if_empty())
    {
        return;
    }
    else
    {
        while(!group2.if_empty())
        {
            group2.deletePCB();
        }
    }
    }

    if(n==3||n==0)
    {
    if(group3.if_empty())
    {
        return;
    }
    else
    {
        while(!group3.if_empty())
        {
            group3.deletePCB();
        }
    }
    }
}