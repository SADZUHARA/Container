#include "IntArray.h"
#include <iostream>
using namespace std;

IntArray::IntArray() = default; //�������� ������� �� ���������

IntArray::IntArray(int length) : m_length { length }    //�������� ������� � ������� ��������, �������� ���-�.
{
    if (length <= 0)
    {
        throw "������ �� ����� ���� ������ ��� ����� 0";
    }
    if (length > 0)
    m_data = new int[length] {};
    cout << "������ ������ �������� " << length << endl;
}

IntArray::~IntArray()   //���������� ��������� ������ �������
{
    delete[] m_data;    
}

void IntArray::erase()  //����������� ���������� ������ �������
{
    delete[] m_data;      
    
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index)    //���-� ������� � ����������� �������� �������
{
    if (index < 0 || index > m_length)
    {
        throw "��������� ������� ������� �� ������";
    }
    return m_data[index];
}

int IntArray::getLength() const //������� ���������� ������ �������
{
    return m_length; 
}

void IntArray::reallocate(int newLength) //���-� �������� ������ �������. ��� ������������ �������� ����� ����������. ��� ������� �������� ������.
{
    erase();    
    if (newLength <= 0)
    {
        throw "������ ������� �� ����� ���� ������ �� �������� ������ ��� ������ 0";
    }
     
    m_data = new int[newLength];    
    m_length = newLength;
}

void IntArray::resize(int newLength)    //����������� ��������� ������� ������� � ������������ ���������
{
    if (newLength <= 0)
    {
        throw "������ ������� �� ����� ���� ������ �� �������� ������ ��� ������ 0";
    } 

    if (newLength == m_length)  
        return;

    if (newLength <= 0) 
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };    // ENG ������� �� ������ �������� ����� ������

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
             
        for (int index{ 0 }; index < elementsToCopy; ++index)   // ENG ������ �������� �������� ���� �� ������
            data[index] = m_data[index];
    }

    delete[] m_data;    

    m_data = data;
    m_length = newLength;
    cout << "������ ������� ������ �� " << newLength << endl;
}

IntArray::IntArray(const IntArray& a)   //����������� �����������
{
    reallocate(a.getLength());  

    for (int index{ 0 }; index < m_length; ++index) 
        m_data[index] = a.m_data[index];
    cout << "������� ����� ������� �������� " << a.m_length << endl;
}

IntArray& IntArray::operator=(const IntArray& a)    //�������� ������������
{
    if (&a == this)
        return *this;
        
    reallocate(a.getLength()); 
      
    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}

void IntArray::insertBefore(int value, int index)   //���-� ������� �������� � ������
{
    if (index < 0 || index > m_length)  
    {
        throw "����� ������� ������� �� ������, ���������� �������� ����� �������";
    }

    int* data{ new int[m_length + 1] }; 
        
    for (int before{ 0 }; before < index; ++before) 
        data[before] = m_data[before];
        
    data[index] = value;    
        
    for (int after{ index }; after < m_length; ++after) 
        data[after + 1] = m_data[after];
    
    delete[] m_data;    
    m_data = data;
    ++m_length;
}

void IntArray::remove(int index)  //���-� �������� �������� �������
{
    if (index < 0 || index > m_length)  
    {
        throw "����� ������� ������� �� ������, ���������� ������� ������� ";
    }
        
    if (m_length == 1) 
    {
        erase();
        return;
    }
       
    int* data{ new int[m_length - 1] }; 
        
    for (int before{ 0 }; before < index; ++before)
        data[before] = m_data[before];
        
    for (int after{ index + 1 }; after < m_length; ++after) 
        data[after - 1] = m_data[after];
        
    delete[] m_data;    
    m_data = data;
    --m_length;
}