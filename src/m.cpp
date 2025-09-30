// #include"queuelist.hpp"
// #include"manager.hpp"
// #include"public.hpp"

// queue_list q1,q2,q3;
// void MFQA();//这是优先级队列进程调度算法
// bool process(queue_list& Q);//这是处理进程的函数、
// void manage();//这是管理函数，结合可视化程序写

// int main()//主程序
// {
//     //两个线程一个用于处理,一个用于用户交互
//     thread t1(MFQA,ref(q1),ref(q2),ref(q3));
//     thread t2(manage);
//     t1.join();
//     t2.join();
//     return 0;
// <<<ki

// void MFQA()
// {
//     while(1)
//     {
//         while(q1.if_empty()&&q2.if_empty()&&q3.if_empty())
//         {//循环等待因为全部为空
//         }

//         //一次处理一个PCB且允许打断
//         if(process(q1))//需要写可视化代码!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         ;
//         else if(process(q2))//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         ;
//         else process(q3)//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//         ;
//     }
// }

// bool process(queue_list& Q)
// {
//     if(!Q.if_empty())
//     {    
//         PCB *p = Q.get_PCB();   
//         //处理进程
//         p->had_time+=5;
//         p->need_time-=5;
//         if(p->need_time<=0) p->need_time =0;
//         Q.deletePCB();
//         return true;
//     }
//     else
//     return false;//返回false去处理Q+1;
// }

// void manage()
// {
//     while(1)
//     {
//         //点击选项执行相应的函数!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     }
// }