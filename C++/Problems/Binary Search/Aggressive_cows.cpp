// Problem Statement:
// You are given N stalls (positions in a barn) and C cows.
// Place the cows in the stalls such that the minimum distance between any two cows is maximized.
// Return this maximum minimum distance.

// assumption: stalls are sorted
#include <iostream>
#include <vector>
using namespace std;

bool check(int dist, vector<int>& arr, int cows){
    int count = 1; // first row placed;
    int pos = arr[0];
    for(int i : arr){
        if(i - pos >= dist){
            count++;
            pos = i;
        }
        if(count >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows){
    int low = 1;
    int high = stalls.back() - stalls[0];
    int ans = 0; 

    while(low <= high){
        int mid = (low + high) / 2;
        if(check(mid, stalls, cows)){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> stalls = {1, 2, 4, 8, 9};
    int cows = 3;

    cout << "Maximum Minimum Distance = " << aggressiveCows(stalls, cows) << endl;

    return 0;
}