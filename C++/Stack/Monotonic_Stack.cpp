// A Monotonic Stack is a stack that is either increasing or decreasing. It is commonly used to efficiently solve problems involving comparisons between elements, like:

// Next Greater Element (NGE)
// Previous Smaller Element
// Stock Span
// Largest Rectangle in Histogram

// Types of Monotonic Stack:

//        Type	                        Maintains Order	            Usage Example
// Monotonically Increasing	   Top always has smallest value	Next smaller element
// Monotonically Decreasing	   Top always has largest value	    Next greater element

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


vector<int> nextGreaterElement(vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    vector <int> res(n, -1);
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && arr[i] >= arr[s.top()]){ 
            s.pop();
        }
        if(!s.empty())
            res[i] = arr[s.top()]; 
        s.push(i);
    }
    return res;
}

vector<int> nextSmallerElement(vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    vector <int> res(n, -1);
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(!s.empty())
            res[i] = arr[s.top()];
        s.push(i);
    }
    return res;
}

vector<int> previousGreaterElement(vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    vector <int> res(n, -1);
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[i] <= arr[s.top()]){
            s.pop();
        }
        if(!s.empty())
            res[i] = arr[s.top()];
        s.push(i);
    }
    return res;
}

vector<int> previousSmallerElement(vector<int>& arr){
    int n = arr.size();
    stack<int> s;
    vector <int> res(n, -1);
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[i] >= arr[s.top()]){
            s.pop();
        }
        if(!s.empty())
            res[i] = arr[s.top()];
        s.push(i);
    }
    return res;
}


int main(){
    vector<int> nums = {4, 5, 2, 10, 8};

    vector<int> result = nextGreaterElement(nums);
    cout << "Next Greater Elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    result = nextSmallerElement(nums);
    cout << "Next Smaller Elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    result = previousGreaterElement(nums);
    cout << "Previous Greater Elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    result = previousSmallerElement(nums);
    cout << "Previous Smaller Elements: ";
    for (int val : result)
        cout << val << " ";
    cout << endl;

    return 0;
}