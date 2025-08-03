// If we cancel out each occurrence of an element x with a different element y, 
// the element left (if any) will be the majority one with occurance more than n/2 times

#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int votes = 0;
    int ans = 0; 
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (votes == 0) {
            ans = nums[i];
        }
        if(ans == nums[i])
            votes++;
        else
            votes--;
    }
    // now check if ans freq is more than n/2 or not
    int freq = 0;
    for(int i = 0; i < n; i++)
        if(nums[i] == ans)
            freq++;
    
    return (freq > n/2) ? ans : -1;
}

int main(){
    vector<int> nums = {1,3,3,2,3,1,3,2,3,1,3,4,3,4,3,2,3,1,3};
    cout << "Majority Element(exist): " << majorityElement(nums) << endl;

    vector<int> nums1 = {1,2,4,5,4,3,4,3,2,3,1,3};
    cout << "Majority Element(does not exist): " << majorityElement(nums1) << endl;
}