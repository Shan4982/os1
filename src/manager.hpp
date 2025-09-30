//这是一个管理类，用于用户交互
#pragma once
#include"public.hpp"
#include<QString>
#include<string>
#include<QTextBrowser>

   struct st
{
    QTextBrowser* name;
    QTextBrowser* time;
    st* next = nullptr;
};

class connect_q_t
{
    public:
 
    int num = 0;
    std::unique_ptr<st> one;
    std::unique_ptr<st> two;
    std::unique_ptr<st> three;

    connect_q_t()
    {
        one = std::make_unique<st>();
        two = std::make_unique<st>();
        three = std::make_unique<st>();
    one->next = two.get();
    two->next = three.get();
    three->next = nullptr;
    };
};