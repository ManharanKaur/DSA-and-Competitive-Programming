#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generate(int rows){
    vector<vector<int>> pascal;
    for (int i = 0; i < rows; i++){
        vector<int> arr;
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i)
                arr.push_back(1);
            else
                arr.push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
        }
        pascal.push_back(arr);
    }
    return pascal;
}

int main(){
    int x = 7; // generate pascle of 5 rows
    vector<vector<int>> pascal = generate(x);
    for (int i = 0; i < pascal.size(); i++)
    {
        for (int j = 0; j < pascal[i].size(); j++)
            cout << pascal[i][j] << " ";
        cout << endl;
    }
    
}