#include "IntArray.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
		
	try
	{
		int r = 6; // размер массива
		class IntArray arr(r);	//создаём массив размером "r"
		cout << endl;

		int sum = 10;
		for (int i = 0; i < arr.getLength(); i++)
		{
			arr[i] = sum;
			sum += 10;
		}

		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << "элемент " << i << " равен " << arr.operator[](i) << endl; //показывает елемент массива 
		}
		cout << endl;

		cout << "элемент " << 5 << " равен " << arr.operator[](5) << endl; //показывает елемент массива 
		cout << endl;

		cout << "общий размер массива " << arr.getLength() << endl; //показать размер массива
		cout << endl;

		//arr.reallocate(8);	//задаём новый размер массива БЕЗ копирования элементов массива

		arr.resize(4);	//задаём новый размер массива с копирование элементов массива
		cout << endl;

		cout << "общий размер массива " << arr.getLength() << endl;	//снова показываем размер массива 
		cout << endl;

		class IntArray arr1(arr);	//создаём копию массива
		cout << endl;

		cout << "общий размер копии массива " << arr1.getLength() << endl; //показать размер массива
		cout << endl;

		//arr1.operator=(arr);
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "элемент " << i << " равен " << arr1.operator[](i) << endl; //показывает елемент массива 
		}
		cout << endl;

		arr1.insertBefore(80, 2);	//добавляем 2й элемента массива с значением 80, удлиняем массив на одно значение
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "элемент " << i << " равен " << arr1.operator[](i) << endl; //показывает елемент массива 
		}
		cout << endl;

		arr1.remove(3);	//удаляем 3й элемент массива
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "элемент " << i << " равен " << arr1.operator[](i) << endl; //показывает елемент массива 
		}
		cout << endl;
	}

	catch (const char* exception)
	{
		cout << "Исключение: " << exception << endl;
	}

	return 0;
}