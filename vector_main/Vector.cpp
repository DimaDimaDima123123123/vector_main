#include "Vector.h"
#include<iostream>
#include<Windows.h>
using namespace std;

Vector::Vector()
{
    arr = nullptr;
    size = 0;
}

Vector::Vector(int s)
{
    size = s;
    arr = new int[size] {0};
}

Vector::~Vector()
{
    delete[] arr;
    size = 0;
}

void Vector::InputRand()
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % 41 - 20; // [-20, +20]
    }
}

void Vector::Print()
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a)
{
    int* temp = new int[size + 1];   // создаем новый массив (тек размер +1)

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i]; // копируем текущие значения старого массива в новый массив
    }
    temp[size] = a; // инициализация последнего элемента параметром метода

    delete[] arr; // удаление старого массива!

    arr = temp; // перенаправляем указатель в объекте на новый дин. массив
    size++;
}

int Vector::PopBack()
{
    if (size == 0) return -1; // проверка на пустой массив

    int* temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = arr[i];
    }
    int el = arr[size - 1]; // достаем последний элемент старого массива ДО удаления

    delete[] arr;
    arr = temp;
    size--;

    return el;
}

// 1
void Vector::AddFirst(int a)
{
    int* temp = new int[size + 1];

    temp[0] = a; 

    for (int i = 0; i < size; i++)
    {
        temp[i + 1] = arr[i]; 
    }

    delete[] arr;

    arr = temp;
    size++;
}

// 2
void Vector::InsertAt(int index, int value)
{
    if (index < 0 || index > size) return; 

    int* temp = new int[size + 1]; 

    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i]; 
    }

    temp[index] = value; 

    for (int i = index; i < size; i++)
    {
        temp[i + 1] = arr[i];
    }

    delete[] arr; 

    arr = temp; 
    size++;
}

// 3
int Vector::DeleteAt(int index)
{
    if (index < 0 || index >= size) return -1; 

    int* temp = new int[size - 1]; 
    int el = arr[index];

    for (int i = 0; i < index; i++)
    {
        temp[i] = arr[i]; 
    }

    for (int i = index + 1; i < size; i++)
    {
        temp[i - 1] = arr[i]; 
    }

    delete[] arr; 

    arr = temp; 
    size--;

    return el;
}

// 4
int Vector::DeleteFirst()
{
    if (size == 0) return -1; 

    int* temp = new int[size - 1]; 
    int el = arr[0]; 

    for (int i = 1; i < size; i++)
    {
        temp[i - 1] = arr[i]; 
    }

    delete[] arr; 

    arr = temp; 
    size--;

    return el;
}

// 5
void Vector::MergeArray(const int* newArr, int newSize)
{
    int* temp = new int[size + newSize]; 

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i]; 
    }

    for (int i = 0; i < newSize; i++)
    {
        temp[size + i] = newArr[i]; 
    }

    delete[] arr;

    arr = temp;
    size += newSize;
}

//

Vector& Vector::operator+=(int count)
{
    int* temp = new int[size + count];  // новый массив (+размер)

    for (int i = 0; i < size; i++)
    {
        temp[i] = arr[i];  // копирка старых элементов
    }

    for (int i = size; i < size + count; i++)
    {
        temp[i] = 0;  // иниц. новых элементов со значеним 0 или другим
    }

    delete[] arr;    // удаление старого
    arr = temp;      // присваивание нового
    size += count;

    return *this;
}

Vector& Vector::operator-=(int count)
{
    if (size < count) return *this;  // размер меньше - возвращаение без изменений
    int* temp = new int[size - count];  // новый уменш. масив

    for (int i = 0; i < size - count; i++)
    {
        temp[i] = arr[i];  // копирка старых эл. кроме последних cout
    }

    delete[] arr;
    arr = temp;
    size -= count;

    return *this;
}

Vector& Vector::operator*=(int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] *= value;  // умножение каждого объекта на значение
    }

    return *this;
}

Vector operator-(int count, const Vector& vec)
{
    if (vec.size <= count) return Vector(0);  // если удаление больше или такого же кол-ва эл., сколько есть

    Vector result(vec.size - count);  // новый вектор(-размер)

    for (int i = 0; i < result.size; i++)
    {
        result.arr[i] = vec.arr[i + count];  // копирование эл. начиная с каунт
    }

    return result;
}

