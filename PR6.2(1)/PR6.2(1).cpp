#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i < size)
    {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else
        cout << endl;
}

int Count(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return 1 + Count(a, size, i + 1);
        else
            return Count(a, size, i + 1);
    }
    return 0;
}

void Modify(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            a[i] = 0;
        Modify(a, size, i + 1);
    }
}

int Sum(int* a, const int size, int i)
{
    if (i < size)
    {
        return a[i] + Sum(a, size, i + 1);
    }
    return 0;
}

int main()
{
    srand(time(0));
    const int size = 15;
    int a[size];

    int Low = 1;
    int High = 100;

    Create(a, size, Low, High, 0);
    cout << " array:  " << endl;// масив
    Print(a, size, 0);

    cout << "Odd Elements " << Count(a, size, 0) << endl;//непарні елементи

    Modify(a, size, 0);
    cout << "Modified array: " << endl;//Модифікований масив
    Print(a, size, 0);

    cout << "The sum of all elements: " << Sum(a, size, 0) << endl;//Сума всіх елементів:

    return 0;
}

