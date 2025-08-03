// Problem Statement
// You are given an array pages[] where pages[i] represents the number of pages in the i-th book. 
// There are m students, and your task is to allocate books such that:

// Each student gets at least one book.
// Each book is allocated to only one student.
// The books are distributed in order (contiguous allocation).

// Goal
// Minimize the maximum pages assigned to any student under these constraints.


//  We will try to find out our answer in RANGE of possible answers.
// check mid, if mid is invalid move to right otherwise left

#include <iostream>
#include <vector>
using namespace std;

bool isValid(vector<int> &arr, int m, int n, int allowed_pages){
    int st = 1, page = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > allowed_pages) return false;
        if(page + arr[i] <= allowed_pages)
            page += arr[i];
        else{
            st++;
            if(st > m) return false;
            page = arr[i];
        }
    }
    return true;
}

int bookAllocation(vector<int> &pages, int m,int n) {
    if(m > n) return -1;
    int s = 0, e = 0;
    for( int i : pages)
        e += i;
    
    int ans = -1;
    while(s <= e){
        int mid = s + (e - s)/2; // max allowed pages
        if(isValid(pages, m, n, mid)){
            ans = mid;
            e = mid - 1;
        }
        else 
            s = mid + 1;
    }
    return ans;
}

int main(){
    int m = 5;
    vector<int> pages = {50, 40, 60, 40, 50, 30, 30, 20, 50, 10};
    int n = pages.size();
    bookAllocation(pages,m,n);
    cout << "Maximum pages assigned to any student is " << bookAllocation(pages, m, n) << endl;
}