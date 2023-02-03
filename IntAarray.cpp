#include "IntArray.h"
#include <iostream>
using namespace std;

IntArray::IntArray() = default; //создание массива по умолчанию

IntArray::IntArray(int length) : m_length { length }    //создание массива с заданым размером, основной кон-р.
{
    if (length <= 0)
    {
        throw "массив не может быть меньше или равен 0";
    }
    if (length > 0)
    m_data = new int[length] {};
    cout << "создан массив размером " << length << endl;
}

IntArray::~IntArray()   //деструктор удаляющий размер массива
{
    delete[] m_data;    
}

void IntArray::erase()  //конструктор обнуляющий размер массива
{
    delete[] m_data;      
    
    m_data = nullptr;
    m_length = 0;
}

int& IntArray::operator[](int index)    //кон-р доступа к опредеённому элементу массива
{
    if (index < 0 || index > m_length)
    {
        throw "указанный элемент массива не найден";
    }
    return m_data[index];
}

int IntArray::getLength() const //функция возвращает размер массива
{
    return m_length; 
}

void IntArray::reallocate(int newLength) //кон-р изменяет размер массива. Все существующие элементы будут уничтожены. Эта функция работает быстро.
{
    erase();    
    if (newLength <= 0)
    {
        throw "размер массива не может быть изменён на значение меньше или равено 0";
    }
     
    m_data = new int[newLength];    
    m_length = newLength;
}

void IntArray::resize(int newLength)    //конструктор изменения размера массива с копированием элементов
{
    if (newLength <= 0)
    {
        throw "размер массива не может быть изменён на значение меньше или равено 0";
    } 

    if (newLength == m_length)  
        return;

    if (newLength <= 0) 
    {
        erase();
        return;
    }

    int* data{ new int[newLength] };    // ENG Сначала мы должны выделить новый массив

    if (m_length > 0)
    {
        int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
             
        for (int index{ 0 }; index < elementsToCopy; ++index)   // ENG Теперь копируем элементы один за другим
            data[index] = m_data[index];
    }

    delete[] m_data;    

    m_data = data;
    m_length = newLength;
    cout << "размер массива изменён на " << newLength << endl;
}

IntArray::IntArray(const IntArray& a)   //конструктор копирования
{
    reallocate(a.getLength());  

    for (int index{ 0 }; index < m_length; ++index) 
        m_data[index] = a.m_data[index];
    cout << "создана копия массива размером " << a.m_length << endl;
}

IntArray& IntArray::operator=(const IntArray& a)    //оператор присваивания
{
    if (&a == this)
        return *this;
        
    reallocate(a.getLength()); 
      
    for (int index{ 0 }; index < m_length; ++index)
        m_data[index] = a.m_data[index];

    return *this;
}

void IntArray::insertBefore(int value, int index)   //кон-р вставки элемента в массив
{
    if (index < 0 || index > m_length)  
    {
        throw "такой элемент массива не найден, невозможно вставить новый элемент";
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

void IntArray::remove(int index)  //кон-р удаление элемента массива
{
    if (index < 0 || index > m_length)  
    {
        throw "такой элемент массива не найден, невозможно удалить элемент ";
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