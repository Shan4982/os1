#pragma once
#include "ui_oslab.h"
#include "newcourse.h"
#include <QMainWindow>
#include <QTextBrowser>
#include <QString>
#include "queuelist.hpp"
#include "manager.hpp"
#include<Qtimer>

class oslab : public QMainWindow {
    Q_OBJECT

    QTimer *timer;
friend class newcourse;
public:
    oslab(QWidget* parent = nullptr);
    ~oslab();
public:
    void showPCB();
    void init_q_to_t();
private:
    void on_newButton_clicked();
    void on_startButton_clicked();
    void on_stopButton_clicked();
    void on_clearButton_clicked(int n = 0);
    void receive_pcb(QString nameData,QString timeData);
    void time_out();
    void clear_endtext();
    
    Ui_oslab* ui;
    newcourse newc;
    all_queue manager_list;
    connect_q_t q_to_t;
    connect_q_t q_to_t2;
    connect_q_t q_to_t3;
    QString time;
    int waiting_time;
    int running_time;  
};


