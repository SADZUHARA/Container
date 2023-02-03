#include "IntArray.h"
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "");
		
	try
	{
		int r = 6; // ������ �������
		class IntArray arr(r);	//������ ������ �������� "r"
		cout << endl;

		int sum = 10;
		for (int i = 0; i < arr.getLength(); i++)
		{
			arr[i] = sum;
			sum += 10;
		}

		for (int i = 0; i < arr.getLength(); i++)
		{
			cout << "������� " << i << " ����� " << arr.operator[](i) << endl; //���������� ������� ������� 
		}
		cout << endl;

		cout << "������� " << 5 << " ����� " << arr.operator[](5) << endl; //���������� ������� ������� 
		cout << endl;

		cout << "����� ������ ������� " << arr.getLength() << endl; //�������� ������ �������
		cout << endl;

		//arr.reallocate(8);	//����� ����� ������ ������� ��� ����������� ��������� �������

		arr.resize(4);	//����� ����� ������ ������� � ����������� ��������� �������
		cout << endl;

		cout << "����� ������ ������� " << arr.getLength() << endl;	//����� ���������� ������ ������� 
		cout << endl;

		class IntArray arr1(arr);	//������ ����� �������
		cout << endl;

		cout << "����� ������ ����� ������� " << arr1.getLength() << endl; //�������� ������ �������
		cout << endl;

		//arr1.operator=(arr);
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "������� " << i << " ����� " << arr1.operator[](i) << endl; //���������� ������� ������� 
		}
		cout << endl;

		arr1.insertBefore(80, 2);	//��������� 2� �������� ������� � ��������� 80, �������� ������ �� ���� ��������
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "������� " << i << " ����� " << arr1.operator[](i) << endl; //���������� ������� ������� 
		}
		cout << endl;

		arr1.remove(3);	//������� 3� ������� �������
		for (int i = 0; i < arr1.getLength(); i++)
		{
			cout << "������� " << i << " ����� " << arr1.operator[](i) << endl; //���������� ������� ������� 
		}
		cout << endl;
	}

	catch (const char* exception)
	{
		cout << "����������: " << exception << endl;
	}

	return 0;
}