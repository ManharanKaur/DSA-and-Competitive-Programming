#include <iostream>
using namespace std;

int main() {
    int input_arr[] = {1,2,1,1,3,4,0,5,6,1,0,1};
    int n = sizeof(input_arr)/sizeof(input_arr[0]);
    int max = 0;
    for (int i = 0; i < n; i++)
        max = input_arr[i] >= max ? input_arr[i] : max;
    
    int count_arr[max + 1]; // count array is of size max + 1
    for (int i = 0; i <= max; i++) // initialize count array with zeros
        count_arr[i] = 0;

    for (int i = 0; i < n; i++) // count occurrences of each number
        count_arr[input_arr[i]] += 1;
    
    for (int i = 1; i <= max; i++) // make cumulative array
        count_arr[i] += count_arr[i - 1];

    int output_arr[n];
    for (int i = 0; i < n; i++){ // output array
        output_arr[count_arr[input_arr[i]] - 1] = input_arr[i];
        count_arr[input_arr[i]] -= 1;
    }
    for (int i = 0; i < n; i++)
        cout << output_arr[i] << " ";
}