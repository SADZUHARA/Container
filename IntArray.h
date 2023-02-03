#pragma once
#include <iostream>
using namespace std;

#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray
{
private:
    int m_length{}; //размер массива
    int* m_data{};

public:
    IntArray();
    IntArray(int length);
    ~IntArray();
    void erase();
    int& operator[](int index);
    int getLength() const;
    void reallocate(int newLength); 
    void resize(int newLength); 
    IntArray(const IntArray& a);
    IntArray& operator=(const IntArray& a);
    void insertBefore(int value, int index);
    void remove(int index);
};

#endif