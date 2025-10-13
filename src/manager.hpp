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
    bool if_empty();
    int num = 7;
    std::unique_ptr<st> one;
    std::unique_ptr<st> two;
    std::unique_ptr<st> three;
    std::unique_ptr<st> four;
    std::unique_ptr<st> five;
    std::unique_ptr<st> six;
    std::unique_ptr<st> seven;
    connect_q_t()
    {
        one = std::make_unique<st>();
        two = std::make_unique<st>();
        three = std::make_unique<st>();
        four = std::make_unique<st>();
        five = std::make_unique<st>();
        six = std::make_unique<st>();
        seven = std::make_unique<st>();
    one->next = two.get();
    two->next = three.get();
    three->next = four.get();
    four->next = five.get();
    five->next = six.get();
    six->next =  seven.get();
    seven->next = nullptr;
    };
};