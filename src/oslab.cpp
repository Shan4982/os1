#include "oslab.h"
#include <QApplication>



oslab::oslab(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_oslab)
{
    ui->setupUi(this);
    running_time =0;
    waiting_time =0;



    timer = new QTimer(this);
    timer->setInterval(1000); // 1000 ºÁÃë = 1 Ãë

    init_q_to_t();

    ///connect ??

    connect(timer, &QTimer::timeout, this, &oslab::time_out);
  
    connect(ui->newButton, &QPushButton::clicked,this, &oslab::on_newButton_clicked);

    connect(ui->clearButton, &QPushButton::clicked, this, &oslab::on_clearButton_clicked);

    connect(&newc,&newcourse::dataSent_oslab,this,&oslab::receive_pcb);

    connect(ui->startButton,&QPushButton::clicked,this,&oslab::on_startButton_clicked);

    connect(ui->stopButton,&QPushButton::clicked,this,&oslab::on_stopButton_clicked);

}

oslab::~oslab()
{
    delete ui; 
}

void oslab::on_newButton_clicked()
{
    newc.exec();
}

void oslab::on_startButton_clicked()
{
    timer->start(1000);
    ui->startButton->setStyleSheet("background-color: #09ff00ff; color: green;");
    ui->stopButton->setStyleSheet("border: none;");
}

void oslab::on_stopButton_clicked()
{
    timer->stop();
    ui->stopButton->setStyleSheet("background-color: #ff0000ff; color: red;");
    ui->startButton->setStyleSheet("border: none;");
}

void oslab::showPCB()
{

    st* temp_st = q_to_t.one.get();
    PCB* temp = manager_list.group1.get_now();
    
    if(temp == nullptr)
    on_clearButton_clicked(1);
    while(temp_st!=nullptr)
    {
        if(temp!=nullptr)
        {
        if(temp_st && temp_st->name && temp_st->time) {
            temp_st->name->setText(QString::fromStdString(temp->name));
            temp_st->time->setText(QString::number(temp->need_time));
            temp = temp->next;
            }
        }
        else
        {
            temp_st->name->clear();
            temp_st->time->clear();
        }
            temp_st = temp_st->next;
            
        
    }


    temp_st = q_to_t2.one.get();
    temp = manager_list.group2.get_now();
    
    if(temp == nullptr)
    on_clearButton_clicked(2);
    while(temp_st!=nullptr)
    {
        if(temp!=nullptr)
        {
        if(temp_st && temp_st->name && temp_st->time) {
            temp_st->name->setText(QString::fromStdString(temp->name));
            temp_st->time->setText(QString::number(temp->need_time));
            temp = temp->next;
        }
        }
        else
        {
            temp_st->name->clear();
            temp_st->time->clear();
        }
        temp_st = temp_st->next;
    }

    temp_st = q_to_t3.one.get();
    temp = manager_list.group3.get_now();
    
    if(temp == nullptr)
    on_clearButton_clicked(3);
    while(temp_st!=nullptr)
    {
        if(temp!=nullptr)
        {
        if(temp_st && temp_st->name && temp_st->time) {
            temp_st->name->setText(QString::fromStdString(temp->name));
            temp_st->time->setText(QString::number(temp->need_time));
            temp = temp->next;
        }
        }
        else
        {
            temp_st->name->clear();
            temp_st->time->clear();
        }
        temp_st = temp_st->next;
    }


}

void oslab::on_clearButton_clicked(int n)
{

    if(n==1||n==0)
    {
    int num = q_to_t.num;
    st* temp_st = q_to_t.one.get();
    while(num--)
    {
        temp_st->name->clear();
        temp_st->time->clear();
        temp_st = temp_st->next;
    }
    manager_list.clear(1);
    }
    
    if(n==2||n==0)
    {
    int num =q_to_t2.num;
    st* temp_st = q_to_t2.one.get();
    while(num--)
    {
        temp_st->name->clear();
        temp_st->time->clear();
        temp_st = temp_st->next;
    }
    manager_list.clear(2);
    }


    if(n==3||n==0)
    {
    int num =q_to_t3.num;
    st* temp_st = q_to_t3.one.get();
    while(num--)
    {
        temp_st->name->clear();
        temp_st->time->clear();
        temp_st = temp_st->next;
    }
    manager_list.clear(3);
    }
}



void oslab::receive_pcb(QString nameData,QString timeData)
{

    PCB * p = new PCB(nameData.toStdString(),timeData.toInt());
    manager_list.addPCB(p);
    showPCB();
}

void oslab::init_q_to_t()
{
    q_to_t.one->name = ui->group1name1;
    q_to_t.one->time = ui->group1time1;
    q_to_t.two->name = ui->group1name2;
    q_to_t.two->time = ui->group1time2;
    q_to_t.three->name = ui->group1name3;
    q_to_t.three->time = ui->group1time3;
    q_to_t.four->name = ui->group1name4;
    q_to_t.four->time = ui->group1time4;
    q_to_t.five->name = ui->group1name5;
    q_to_t.five->time = ui->group1time5;
    q_to_t.six->name = ui->group1name6;
    q_to_t.six->time = ui->group1time6;
    q_to_t.seven->name = ui->group1name7;
    q_to_t.seven->time = ui->group1time7;
    q_to_t.seven->next = nullptr;

    q_to_t2.one->name = ui->group2name1;
    q_to_t2.one->time = ui->group2time1;
    q_to_t2.two->name = ui->group2name2;
    q_to_t2.two->time = ui->group2time2;
    q_to_t2.three->name = ui->group2name3;
    q_to_t2.three->time = ui->group2time3;
    q_to_t2.four->name = ui->group2name4;
    q_to_t2.four->time = ui->group2time4;
    q_to_t2.five->name = ui->group2name5;
    q_to_t2.five->time = ui->group2time5;
    q_to_t2.six->name = ui->group2name6;
    q_to_t2.six->time = ui->group2time6;
    q_to_t2.seven->name = ui->group2name7;
    q_to_t2.seven->time = ui->group2time7;
    q_to_t2.seven->next = nullptr;

    q_to_t3.one->name = ui->group3name1;
    q_to_t3.one->time = ui->group3time1;
    q_to_t3.two->name = ui->group3name2;
    q_to_t3.two->time = ui->group3time2;
    q_to_t3.three->name = ui->group3name3;
    q_to_t3.three->time = ui->group3time3;
    q_to_t3.four->name = ui->group3name4;
    q_to_t3.four->time = ui->group3time4;
    q_to_t3.five->name = ui->group3name5;
    q_to_t3.five->time = ui->group3time5;
    q_to_t3.six->name = ui->group3name6;
    q_to_t3.six->time = ui->group3time6;
    q_to_t3.seven->name = ui->group3name7;
    q_to_t3.seven->time = ui->group3time7;
    q_to_t3.seven->next = nullptr;
}

void oslab::time_out()
{
    if(manager_list.if_empty())
    {
    waiting_time+=1;
    int temp = waiting_time;
    ui->lineEdit_2->setText(QString::number(temp));
    }
    else
    {
        waiting_time = 0;
        ui->lineEdit_2->setText(QString::number(waiting_time));
        running_time+=1;
        int temp = running_time;
        ui->lineEdit->setText(QString::number(temp));
        manager_list.updata();
    }
    showPCB();
}


