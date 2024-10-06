#pragma once
class Vector
{
    int* arr;
    int size;
public:
    Vector();
    ~Vector();

    Vector(int s);
    void InputRand();                                // ������������� ���������� �������
    void Print();                                    // ����� �� �������

    void PushBack(int a);                            // ���������� � ����� �������
    int PopBack();                                   // �������� ���������� ��������

    void AddFirst(int a);                            // 1)��������� 1 �������� �� ������ �������
    void InsertAt(int index, int value);             // 2)���������� �� �������, ������ � �������� �������� ��� ��������
    int DeleteAt(int index);                         // 3)�������� �� �������
    int DeleteFirst();                               // 4)�������� ������� ��������

    void MergeArray(const int* newArr, int newSize); // 5)���������� ������� � ����� �������� �������!

    Vector& operator+=(int count);  // ���������� count ��������� � ����� �������
    Vector& operator-=(int count);  // ���������� ������� ������� �� count
    Vector& operator*=(int value);  // ��������� ���� ��������� �� value
    friend Vector operator-(int count, const Vector& vec);  // �������� count ������ ���������

};
                           