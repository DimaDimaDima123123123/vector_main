#pragma once
class Vector
{
    int* arr;
    int size;
public:
    Vector();
    ~Vector();

    Vector(int s);
    void InputRand();                                // инициализаци€ случайными числами
    void Print();                                    // вывод на консоль

    void PushBack(int a);                            // добавление в конец массива
    int PopBack();                                   // удаление последнего элемента

    void AddFirst(int a);                            // 1
    void InsertAt(int index, int value);             // 2
    int DeleteAt(int index);                         // 3
    int DeleteFirst();                               // 4

    void MergeArray(const int* newArr, int newSize); // 5
};
                             /*
                                ƒобавл€ем следующие методы:
                                1)ƒобаление 1 значени€ на начало массива
                                2)ƒобавление по индексу, индекс и значение передаем как параметр
                                3)”даление по индексу
                                4)удаление первого элемента

                                5)ƒобавление массива в конец текущего массива!


                             */