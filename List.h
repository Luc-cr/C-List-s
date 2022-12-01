#pragma once
#include "iostream"

using namespace std;


class List
{
    struct Header
    {
        char position;
        size_t size;
        intptr_t *next;
    };

    public:
    List(size_t type);
    void push_back(char item);
    void print();
    size_t align(size_t n);
    private:

    char counter = 0;
    size_t bytes;
    intptr_t *firstAddress = NULL;
    intptr_t *lastAddress;
};