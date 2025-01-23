#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> LeftHalf, vector<int> RightHalf){
    vector <int> merged; //empty array
    int i = 0, j = 0;

    int l = LeftHalf.size();
    int r = RightHalf.size();

    // Compare each element of LeftHalf and RightHalf and merge them
    while (i < l && j < r)
    {
        if (LeftHalf[i] <= RightHalf[j])
        {
            merged.push_back(LeftHalf[i]);
            i++;
        }
        else{
            merged.push_back(RightHalf[j]);
            j++;
        }
    }
    while (i < l)
    {
        merged.push_back(LeftHalf[i]);
        i++;
    }
    while (j < r)
    {
        merged.push_back(RightHalf[j]);
        j++;
    }
    return merged;
}

vector<int> mergeSort(vector<int> arr, int left, int right)
{
    if (left >= right) {  // Base case for recursion
        return vector<int>(1, arr[left]);  // Returning a single-element array
    }

    int mid = left + (right - left) / 2; // Calculate middle index
    vector<int> LeftHalf = mergeSort(arr, left, mid);
    vector<int> RightHalf = mergeSort(arr,mid+1,right);

    // Merge two sorted arrays
    // subarrays sent to merge function
    return merge(LeftHalf, RightHalf);
}

int main()
{
    vector<int> arr{1, 9, 2, 8, 3, 7, 4, 6, 5};
    vector<int> sorted_arr = mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < sorted_arr.size(); i++)
    {
        cout << sorted_arr[i] << " ";
    }
}