/*
COUNT INVERSIONS PROBLEM
An inversion in an array is a pair of indices (i, j) such that:
    i < j  AND  arr[i] > arr[j]
- The order of elements is opposite to what it should be in a sorted array
- More inversions → array is more unsorted
Example:
Array: [2, 4, 1, 3, 5]
Inversions are:
(2, 1)  → indices (0, 2)
(4, 1)  → indices (1, 2)
(4, 3)  → indices (1, 3)
Total inversions = 3

Optimized Approach (Using Merge Sort):
- Divide the array into two halves
- Recursively count inversions in left half
- Recursively count inversions in right half
- Count cross inversions while merging

Key Observation During Merge:
- If left[i] <= right[j]:
    → No inversion
- If left[i] > right[j]:
    → All remaining elements from left[i] to left[mid]
      will form inversions with right[j]
So:
    inversions += (mid - i + 1)

Time Complexity:
- O(n log n)
    (Divide step: log n, Merge step: n)
Space Complexity:
- O(n)
    (Temporary array used during merge)
*/

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int s, int mid, int e){
    vector<int> temp;
    int i = s, 
        j = mid + 1,
        count_inversion = 0;

    while(i <= mid && j <= e){
        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            count_inversion += mid - i + 1;
        }
    }
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= e) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int i = 0; i < temp.size(); i++){
        arr[i+s] = temp[i];
    }

    return count_inversion;
}

int count_inversions(vector<int> &arr, int s, int e){
    if(s < e){
        int mid = s + (e-s)/2;
        int left_inversion = count_inversions(arr,s, mid);
        int right_inversion = count_inversions(arr,mid+1, e);
        
        int merge_inversions = merge(arr,s,mid,e);
        return left_inversion + right_inversion + merge_inversions;
    }
    return 0;
}

int main(){
    vector<int> arr = {9,1,8,2,7,3,6,4,5};
    cout << "Inversions: " << count_inversions(arr,0,arr.size()-1);
}
