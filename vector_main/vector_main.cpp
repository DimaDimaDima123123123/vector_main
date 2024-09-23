#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
    srand(time(0));
    Vector obj1(5);
    obj1.InputRand();
    obj1.Print();

    obj1.AddFirst(50); // Добавляем элемент в начало
    obj1.Print();

    obj1.InsertAt(2, 75); // Вставляем элемент на индекс 2
    obj1.Print();

    int removed = obj1.DeleteAt(3); // Удаляем элемент по индексу 3
    obj1.Print();
    cout << "Removed element at index 3 = " << removed << endl;

    int first = obj1.DeleteFirst(); // Удаляем первый элемент
    obj1.Print();
    cout << "First removed = " << first << endl;

    // Добавление массива в конец
    int arrToAdd[] = { 300, 400, 500 };
    obj1.MergeArray(arrToAdd, 3);
    obj1.Print();
}
