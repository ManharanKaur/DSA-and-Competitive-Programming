#include <iostream>
#include <vector>
using namespace std;

void get_perm(vector<int>&  arr, int idx, vector<vector<int> > & answer){
    if(idx == arr.size()){
        answer.push_back(arr);
        return;
    }
    for(int i = idx; i < arr.size(); i++){
        swap(arr[idx], arr[i]);
        get_perm(arr, idx+1, answer);
        swap(arr[idx], arr[i]);
    }
}

vector<vector<int> > permutations(vector<int>& arr){
    vector<vector<int> > answer;
    get_perm(arr, 0, answer);

    return answer;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int> > perm = permutations(arr);

    for(int i = 0; i < perm.size(); i++){
        for(int j = 0; j < perm[i].size(); j++){
            cout << perm[i][j] << " ";
        }
        cout << endl;
    }
}