#include "newcourse.h"
#include "manager.hpp"

newcourse::newcourse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::newcourse)
{
    ui->setupUi(this);

    connect(ui->cancel, &QPushButton::clicked, this, &newcourse::on_cancleButton_clicked);
    connect(ui->yes, &QPushButton::clicked, this,&newcourse::on_yesButton_clicked);
}

newcourse::~newcourse()
{
    delete ui;
}

void newcourse::on_cancleButton_clicked()
{
    this->close();//关闭窗口
}


bool newcourse::if_empty()
{
    if (Qname.isEmpty() || Qtime.isEmpty()) {
        return true;
    }
    else {
        return false;
    }
}

QPushButton *  newcourse::get_button()
{
    return ui->yes;
}

void newcourse::on_yesButton_clicked()
{
    QString Qname = ui->name->text();//获取进程名称
    QString Qtime = ui->time->text();//
    emit dataSent_oslab(Qname,Qtime);
    ui->name->clear();
    ui->time->clear();
    this->close();
}
