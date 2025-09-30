#include "oslab.h"
#include <QApplication>



oslab::oslab(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui_oslab)
{
    ui->setupUi(this);

    q_to_t.one->name = ui->group1name1;
    q_to_t.one->time = ui->group1time1;
    q_to_t.two = nullptr;

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
            qDebug() << "UI updated:" << temp_st->name->toPlainText().toStdString();// Ìí¼Óµ÷ÊÔÊä³ö
        }
        temp_st = temp_st->next;
        temp = temp->next;
    }
}

void oslab::on_clearButton_clicked()
{

}


void oslab::receive_pcb(QString nameData,QString timeData)
{
    PCB * p = new PCB(nameData.toStdString(),timeData.toInt());
    group1.addPCB(p);
    showPCB();
}