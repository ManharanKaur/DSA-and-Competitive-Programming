#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void heapifyUP(vector<int> &arr, int i)
{
    int parent = (i - 1) / 2;
    if (i > 0 && arr[parent] < arr[i])
    {
        swap(arr[parent], arr[i]);
        heapifyUP(arr, parent);
    }
}

void heapifyDOWN(vector<int> & arr, int i, int n){
    int extremum = i;
    int left = 2 * extremum + 1; // left child
    int right = 2 * extremum + 2; // right child

    // check if left child is larger than root
    if (left < n && arr[left] > arr[extremum])
        extremum = left;

    // check if right child is larger than root
    if (right < n && arr[right] > arr[extremum])
        extremum = right;

    if (extremum != i){
        swap(arr[i], arr[extremum]);
        heapifyDOWN(arr, extremum, n);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();
    // Build max heap
    for (int i = 0; i < n; i++)
        heapifyUP(arr, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--){
        // Move the root to end
        swap(arr[0], arr[i]);
        heapifyDOWN(arr, 0, i); // call max heapify on the reduced heap
    }
}

int main()
{
    vector<int> arr{1, 9, 2, 8, 3, 7, 4, 6, 5};
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}