#pragma once
#include "iostream"

using namespace std;

struct Header
{
    char position;
    size_t size;
    intptr_t *next;
};
template <class var>
class List
{
    public:
    List();
    void push_back(var item);
    void print();
    var get(int position);
    size_t align(size_t n);

    private:
    unsigned char index = 0;
    size_t bytes;
    intptr_t *firstAddress = NULL;
    intptr_t *lastAddress;
};