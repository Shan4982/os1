#include "oslab.h"
#include "manager.hpp"
#include "public.hpp"
#include "newcourse.h"
#include "queuelist.hpp"
#include <QString>
#include <QTextBrowser>
#include <QApplication>
#pragma comment(lib, "user32.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    oslab w;
    w.show();
    return a.exec();
}