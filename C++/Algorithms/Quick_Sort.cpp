#include <iostream>
#include <vector>
using namespace std;
void swap(int & a, int & b){
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1; // index of smaller element
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]); // swap if current element is smaller than pivot
        }
        
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}


void QuickSort(vector<int>& arr, int low, int high){
    if (low < high)
    {
        // Partition the array and get pivot index
        int pivot = partition(arr,low,high);

        // Recursivly sort elements before and after pivot
        QuickSort(arr, low, pivot - 1);
        QuickSort(arr, pivot + 1, high);
    }
    
}

int main(){
    vector<int> arr = {9,1,8,2,7,3,6,4,5};
    QuickSort(arr, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}