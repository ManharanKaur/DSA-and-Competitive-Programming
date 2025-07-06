// In 1D DP, we solve problems where the solution to a problem depends only on a single dimension
// We use a 1D array dp[i] to store results of subproblems.

// If a problem has:
// Optimal substructure (can be built from smaller parts)
// Overlapping subproblems
// And we only need to store info from previous states (like i-1, i-2), it's 1D DP

// Focus on transition formulas like dp[i] = dp[i-1] + dp[i-2]

// Example 1: Climbing Stairs 
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n){
    if(n <= 2) return n;
    vector<int> dp(n+1, 0);

    dp[1] = 1; // to go to 1st step, there's only 1 way [1 step]
    dp[2] = 2; // to go to 2nd step, there are 2 ways [1 + 1 steps, 2 steps]

    for(int i = 3; i < n+1; i++)
        dp[i] = dp[i - 1] + dp[i - 2]; 
        // at ith step, we can either come from (i-1)th or (i-2)th step.
        // so, we add the ways to reach (i-1)th and (i-2)th
    
    return dp[n]; 
}

int main(){
    int n = 7;

    int ways = climbStairs(n);
    cout << "Number of distinct ways to climb " << n << " stairs: " << ways << endl;
}