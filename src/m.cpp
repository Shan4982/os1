// #include"queuelist.hpp"
// #include"manager.hpp"
// #include"public.hpp"

// queue_list q1,q2,q3;
// void MFQA();//�������ȼ����н��̵����㷨
// bool process(queue_list& Q);//���Ǵ������̵ĺ�����
// void manage();//���ǹ�����������Ͽ��ӻ�����д

// int main()//������
// {
//     //�����߳�һ�����ڴ���,һ�������û�����
//     thread t1(MFQA,ref(q1),ref(q2),ref(q3));
//     thread t2(manage);
//     t1.join();
//     t2.join();
//     return 0;
// }

// void MFQA()
// {
//     while(1)
//     {
//         while(q1.if_empty()&&q2.if_empty()&&q3.if_empty())
//         {//ѭ���ȴ���Ϊȫ��Ϊ��
//         }

//         //һ�δ���һ��PCB���������
//         if(process(q1))//��Ҫд���ӻ�����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
//         //��������
//         p->had_time+=5;
//         p->need_time-=5;
//         if(p->need_time<=0) p->need_time =0;
//         Q.deletePCB();
//         return true;
//     }
//     else
//     return false;//����falseȥ����Q+1;
// }

// void manage()
// {
//     while(1)
//     {
//         //���ѡ��ִ����Ӧ�ĺ���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//     }
//lkk

// }