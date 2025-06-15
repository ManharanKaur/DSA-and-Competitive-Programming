#include <iostream>
#include <vector>
// The Maximum Subarray Problem is to find a contiguous subarray (containing at least one number) 
// in a one-dimensional array of numbers (both positive and negative) which has the largest sum.
using namespace std;
int MaxCrossingSubarray(vector <int> arr, int l, int m, int r){
    int leftsum = INT_MIN;
    int sum = 0;
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        leftsum = max(leftsum, sum);
    }

    int rightsum = INT_MIN;
    sum = 0;
    for (int i = m + 1; i <= r; i++)
    {
        sum += arr[i];
        rightsum = max(rightsum, sum);
    }
    return leftsum + rightsum;
}

int maxSubArray(vector <int> arr, int left, int right){
    if (right == left)
        return arr[left];

    if( right - left == 1){
        return max({arr[left], arr[right], arr[left] + arr[right]});
    }
    
    int mid = left + (right - left) / 2;
    int leftMax = maxSubArray(arr, left, mid);
    int rightMax = maxSubArray(arr, mid + 1, right);
    int crossMax = MaxCrossingSubarray(arr, left, mid, right);
    
    return max({leftMax, rightMax, crossMax});
}

int main(){
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}; // 
    cout << "Maximum Subarray Sum: " << maxSubArray(nums, 0, nums.size() - 1) << endl;
    return 0;
}