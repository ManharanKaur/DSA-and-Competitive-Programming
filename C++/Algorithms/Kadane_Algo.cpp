//Kadane's Algorithm : Maximum Subarray Sum
// how it work:
// it is a sliding window approach
// 1. Initialize max so far result and current sum to the first element of the array.
// 2. Iterate through the array starting from the second element.
// 3. For each element, calculate the maximum of the current element and the sum of th
//    current element and current sum
// 4. Update result if the result from step 3 is greater than current
// 5. Return result at the end of the iteration.
// Time complexity: O(n)
// Space complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(vector <int> &arr){
    int result= arr[0];
    int currentsum = arr[0];
    for (int i = 1; i < arr.size(); i++){
        currentsum = max(arr[i], currentsum+arr[i]); // max of current element and sum of current element and current sum;
        // This is because. if current element is negative, then adding it to current sum will decrease the sum
        // and if it is larger than (currentsum + arr[i]), then our subarray should start from this element
        // this case is possible if our cuttent sum is -ve then adding a +ve num will decrease our sum
        result = max(result, currentsum); // update maximum so far
    }
    return result;
}

int main() {
    vector<int> arr = {4, -1, 2, -7, 5, 3, -2, 9, -8, 6, -3, 4, -5, 7, -6, 1, -4, 10, -2, -1, 8, -9, 12, -3, 14, 15, -10, -6, 3, 5, -8, 9, -2};
    cout << maxSubarraySum(arr);
    return 0;
}