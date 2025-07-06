#include <iostream>
#include <vector>
using namespace std;

void get_comb(vector<int>&  arr, int idx, vector<int>& comb, vector<vector<int> >& answer){
    
    answer.push_back(comb);

    for(int i = idx; i < arr.size(); i++){
        comb.push_back(arr[i]);
        get_comb(arr, i+1, comb, answer);
        comb.pop_back();
    }
}

vector<vector<int> > combinations(vector<int> arr){
    vector<vector<int> > answer;
    vector<int> comb;
    get_comb(arr, 0, comb, answer);

    return answer;
}

int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int> > comb = combinations(arr);

    for(int i = 0; i < comb.size(); i++){
        for(int j = 0; j < comb[i].size(); j++){
            cout << comb[i][j] << " ";
        }
        cout << endl;
    }
}