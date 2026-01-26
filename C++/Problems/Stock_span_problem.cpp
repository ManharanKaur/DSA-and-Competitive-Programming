// Stock Span Problem 
//
// You are given an array price[] of size N,
// where price[i] represents the stock price on day i.
//
// Definition of Stock Span:
// The stock span for a day i is the number of consecutive days
// (starting from day i and going backwards)
// for which the stock price was less than or equal to price[i].
//
// In simple words:
// - Count how many days (including today) you can go back
//   such that the price was <= today's price
// - Stop counting when you find a day with a higher price than today
//
// Important points:
// - The span of the first day is always 1 (only itself).
// - For each day, we look to the LEFT side of the array.
// - Consecutive means days must be continuous (no skipping).
//
// Task:
// Given the array price[], compute the span for each day
// and store it in an array span[].
//
// Example idea (no code):
// price = [100, 80, 60, 70, 60, 75, 85]
// span  = [  1,  1,  1,  2,  1,  4,  6]
//
// Explanation idea:
// - Day 0 (100): no previous days → span = 1
// - Day 1 (80): 100 > 80 → stop → span = 1
// - Day 3 (70): previous 60 <= 70 → include it
//               before that 80 > 70 → stop → span = 2
//
// Constraints usually imply:
// - A brute-force solution is O(N^2)
// - An efficient solution using stack exists in O(N)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};
    vector<int> ans(price.size(),0);
    stack<int> s;

    for (int i = 0; i < price.size(); i++)
    {
        while(!s.empty() && price[s.top()] <= price[i])
            s.pop();

        if(s.empty())
            ans[i] = i+1;
        else
            ans[i] = i - s.top();

        s.push(i);
    }

    for(int i : ans){
        cout << i << " ";
    }
    
}