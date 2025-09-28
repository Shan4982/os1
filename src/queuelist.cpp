#include"queuelist.hpp"


queue_list::queue_list()
{
    
    head = new PCB();
    head->next = nullptr;
    end = head;
    now = head ->next;
}


void queue_list::addPCB(PCB *p)
    {
        p->status=waiting;
        end->next = p;
        end = p;
    }

bool queue_list::deletePCB()
    {   if(now==nullptr)
        {
        cerr <<"now is not exits"<<endl;
        return 0;
        }
        if(now->need_time==0)
        {
            now->status=stop;
            now=now->next;
            return true;//true代表完成
        }
        else
        {
            if(now->where==1)
            {
                now->where=2;
            }
            else 
            {
                now->where =3;
            }
            return false;
        }
    }

bool queue_list::if_empty()
    {
        if(now==nullptr)
        {
        cerr <<"now is not exits"<<endl;
        return 0;
        }
        if(now==end)
        return true;
        else
        return false;
    }


    PCB* queue_list::get_now()
    {

        if(now==nullptr)
        {
        cerr <<"now is not exits"<<endl;
        return nullptr;
        }
        return now;
    }

