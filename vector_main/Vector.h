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

    void AddFirst(int a);                            // 1)ƒобаление 1 значени€ на начало массива
    void InsertAt(int index, int value);             // 2)ƒобавление по индексу, индекс и значение передаем как параметр
    int DeleteAt(int index);                         // 3)”даление по индексу
    int DeleteFirst();                               // 4)удаление первого элемента

    void MergeArray(const int* newArr, int newSize); // 5)ƒобавление массива в конец текущего массива!

    Vector& operator+=(int count);  // добавление count элементов в конец вектора
    Vector& operator-=(int count);  // уменьшение размера вектора на count
    Vector& operator*=(int value);  // умножение всех элементов на value
    friend Vector operator-(int count, const Vector& vec);  // удаление count первых элементов

};
                           