#include <iostream>
using namespace std;
int main(){
    //LINEAR SEARCH (for unsorted array)
    int A[10] = {2,4,6,8,3,7,1,3,5,0};
    int key1 = 3;
    int count = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < count; i++)
    {
        if (A[i] == key1)
        {
            cout << key1 << " at index " << i << "\n";
        }
        else if ( i == count - 1 && A[i] == key1){
            cout << "Element Not Present\n";
        }
    }

    //______________________________________________________
    //BINARY SEARCH (for sorted array)
    int B[10] = {1,4,6,8,9,10,25,45,67,89};
    count = sizeof(B)/sizeof(B[0]);
    int start = 0, end = count - 1;
    int mid, key2 = 10;
    while (start < end)
    {
        mid = start + (end - start)/2; //there maybe case where (start + end) exceed max number limit.
        if (B[mid] == key2){
            cout << key2 << " at index " << mid << "\n";
            break;
        }
        else if(B[mid] < key2){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    
}