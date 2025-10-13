#ifndef NEWCOURSE_H
#define NEWCOURSE_H
#include <QDialog>
#pragma once
#include <QWidget>
#include "ui_newcourse.h"
#include "public.hpp"
#include <QPushButton>

namespace Ui {
class newcourse;
}

class newcourse : public QDialog
{
    Q_OBJECT

public:
    explicit newcourse(QWidget *parent = nullptr);
    bool if_empty();
    ~newcourse();
    QPushButton * get_button();

Q_SIGNALS:
    void dataSent_oslab(QString nameData,QString timeData);
    
private:
    Ui::newcourse *ui;
    void on_cancleButton_clicked();
    void on_yesButton_clicked();
    QString Qname;
    QString Qtime;
};

#endif // NEWCOURSE_H