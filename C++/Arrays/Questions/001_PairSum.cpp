// Write a program that, given an array A[] of n numbers and another number x, determines whether or not
// there exist two elements in S whose sum is exactly x.

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

// Brute Force
// Time complexity O(n^2)
void BruteForce(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == x)
            {
                cout << "Sum present. i.e.\n"
                     << A[i] << "+" << A[j] << "=" << x << endl;
                return;
            }
        }
    }
    cout << "Sum not present.\n";

    return;
}

// By sorting
// Time complexity = O(n^2) + O(n) = O(n^2)
void SortingAlgo(int A[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[i] > A[j])
            {
                swap(A[i], A[j]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }

    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (A[s] + A[e] < x)
            s++;
        else if (A[s] + A[e] > x)
            e--;
        else
        {
            cout << "Sum present. i.e.\n"
                 << A[s] << "+" << A[e] << "=" << x << endl;
            return;
        }
    }
    cout << "Sum not present.\n";
    return;
}

// By using Hash Map
void HashMap(int A[], int n, int x)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }

    bool *hashmap = new bool[max + 1]{};

    int difference;

    for (int i = 0; i < n; i++)
    {
        difference = x - A[i];
        if (difference >= 0 && difference <= max && hashmap[difference])
        {
            cout << "Sum present. i.e.\n" << A[i] << "+" << difference << "=" << x << endl;
            return;
        }

        if (difference >= 0 && difference <= max)
        {
            hashmap[A[i]] = 1;
        }
    }
    cout << "Sum not present.\n";
    return;
}

int main()
{
    int n;
    cout << "Enter no of elements : ";
    cin >> n;

    int *A = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int x;
    cout << "Enter target element : ";
    cin >> x;
    cout << endl;

    //  Brute Force
    cout << "Using Brute Force: \n";
    BruteForce(A, n, x);
    cout << endl;

    //  By Sorting
    cout << "Using Sorting Algorithm: \n";
    SortingAlgo(A, n, x);
    cout << endl;

    // Using Hash Map
    cout << "Using Hash Map: \n";
    HashMap(A, n, x);
    cout << endl;

    return 0;
}