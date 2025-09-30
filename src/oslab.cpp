#include "oslab.h"
#include <QApplication>



oslab::oslab(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_oslab)
{
    ui->setupUi(this);

    init_q_to_t();

    connect(ui->newButton, &QPushButton::clicked,this, &oslab::on_newButton_clicked);

    connect(ui->clearButton, &QPushButton::clicked, this, &oslab::on_clearButton_clicked);

    connect(&newc,&newcourse::dataSent_oslab,this,&oslab::receive_pcb);
}

oslab::~oslab()
{
    delete ui; 
}

void oslab::on_newButton_clicked()
{
    newc.exec();
}

void oslab::showPCB()
{
    
    st* temp_st = q_to_t.one.get();
    PCB* temp = group1.get_now();
    
    while(temp_st!=nullptr&&temp!=nullptr)
    {
        if(temp_st && temp_st->name && temp_st->time) {
            temp_st->name->setText(QString::fromStdString(temp->name));
            temp_st->time->setText(QString::number(temp->need_time));
        }
        temp_st = temp_st->next;
        temp = temp->next;
    }
}

void oslab::on_clearButton_clicked()
{
    int num = q_to_t.num;
    st* temp_st = q_to_t.one.get();
    while(num--)
    {
        temp_st->name->clear();
        temp_st->time->clear();
        temp_st = temp_st->next;
    }
}


void oslab::receive_pcb(QString nameData,QString timeData)
{
    PCB * p = new PCB(nameData.toStdString(),timeData.toInt());
    group1.addPCB(p);
    q_to_t.num++;
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
    q_to_t.three->next = nullptr;
}