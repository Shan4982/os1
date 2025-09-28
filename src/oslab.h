#pragma once
#include "ui_oslab.h"
#include "newcourse.h"
#include <QMainWindow>
#include <QTextBrowser>
#include "queuelist.hpp"
#include "manager.hpp"

class oslab : public QMainWindow {
    Q_OBJECT

friend class newcourse;
public:
    oslab(QWidget* parent = nullptr);
    ~oslab();
public:
    
    void showPCB();
    
private:
void on_newButton_clicked();
void on_startButton_clicked();
    void on_clearButton_clicked();
    void receive_pcb(QString nameData,QString timeData);
    Ui_oslab* ui;
    newcourse newc;
    queue_list group1;
    queue_list group2;
    queue_list group3;
    connect_q_t q_to_t;
};


