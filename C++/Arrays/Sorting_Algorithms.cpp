#include <iostream>
using namespace std;
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}

int main()
{
    // BUBBLE SORT
    int Arr1[] = {4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6};
    int len = sizeof(Arr1) / sizeof(int);
    for (int i = 0; i < len; i++)
    {
        int swapped = false;
        for (int j = 0; j < len - i; j++)
        {
            if (Arr1[j] > Arr1[j + 1])
            {
                swap(Arr1[j], Arr1[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    for (int i = 0; i < len; i++)
    {
        cout << Arr1[i] << ' ';
    }
    cout << endl;

    //__________________________________________________________________
    // INSERTION SORT
    int Arr2[] = {4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6};
    len = sizeof(Arr2) / sizeof(int);
    int key;
    for (int i = 0; i < len; i++)
    {
        key = Arr2[i];
        int j = i - 1;
        while (j >= 0 && Arr2[j] > key)
        {
            Arr2[j + 1] = Arr2[j];
            j--;
        }
        Arr2[j + 1] = key;
    }
    for (int i = 0; i < len; i++)
    {
        cout << Arr2[i] << ' ';
    }
    cout << endl;

    //__________________________________________________________________
    // SELECTION SORT
    int Arr3[] = {4, 7, 2, 9, 3, 9, 0, 3, 7, 1, 7, 8, 5, 6};
    len = sizeof(Arr3) / sizeof(int);
    int min_index;
    for (int i = 0; i < len - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < len; j++)
        {
            if (Arr3[j] < Arr3[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(Arr3[min_index], Arr3[i]);
    }
    for (int i = 0; i < len; i++)
    {
        cout << Arr3[i] << ' ';
    }
    cout << endl;
    //__________________________________________________________________
}