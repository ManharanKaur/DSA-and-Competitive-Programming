// Celebrity Problem
//
// You are given a group of N people at a party.
// The information about who knows whom is provided using a matrix M of size N x N.
//
// Meaning of M[i][j]:
// - M[i][j] = 1  → person i knows person j
// - M[i][j] = 0  → person i does NOT know person j
//
// Definition of a Celebrity:
// A person is called a celebrity if:
// 1) Everyone knows the celebrity
//    → For a celebrity C, M[i][C] = 1 for all i ≠ C
// 2) The celebrity knows no one
//    → For a celebrity C, M[C][i] = 0 for all i
//
// Important points:
// - A person cannot be a celebrity if they know even one person.
// - A person cannot be a celebrity if there exists even one person who does not know them.
// - There can be at most ONE celebrity in the party.
//
// Task:
// Given the matrix M, determine whether a celebrity exists.
// If a celebrity exists, return the index (0-based) of that person.
// If no celebrity exists, return -1.

#include<iostream>
#include <vector>
#include <stack>
using namespace std;

int getCelebrity (vector<vector<int> > arr) {
    int n = arr.size();
    stack <int> s;
    for( int i = 0 ; i < n; i++)
        s.push(i);
    
    while(s.size() > 1){
        int i = s.top();
        s.pop();
        int j = s.top();
        s.pop();

        if(arr[i][j] == 0) s.push(i);
        else s.push(j);
    }

    int celeb = s.top();
    for (int i = 0; i < n; i++)
        if(i != celeb && (arr[i] [celeb] == 0 || arr [celeb] [1] == 1))
            return -1;
        
    return celeb;
    
}
int main() {
    vector<vector<int>> arr = { {0,1,0}, {0,0,0},{0,1,0} };

    int ans = getCelebrity(arr);
    cout << "celebrity is : " << ans << endl;
    return 0;
}