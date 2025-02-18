#include <iostream>
#include <stack>
using namespace std;


stack<int> pushatbottom(stack<int> &s, int x){
    if(s.empty()) {
        s.push(x);
        return s;
    }
    int num = s.top();
    s.pop();

    pushatbottom(s,x); //recursive call

    s.push(num);
    return s;
}

void reverse(stack<int> &s){
    if(s.empty()) return;
    int num = s.top();
    s.pop();
    reverse(s);
    pushatbottom(s,num);
}

void insertsorted(stack<int> &s, int x){
    if(s.empty() || x <= s.top()){
        s.push(x);
        return;
    }
    int n = s.top();
    s.pop();
    insertsorted(s,x);
    s.push(n);
}

void sortstack(stack<int> &s){
    if(s.empty()) return;
    int num = s.top();
    s.pop();
    sortstack(s);

    insertsorted(s,num);
}

void display(stack<int> s){
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
int main(){
    stack<int> s;
    s.push(3);
    s.push(-7);
    s.push(9);
    s.push(-1);
    s.push(5);
    cout << "Original Stack: ";
    display(s);
    cout << "Push an element at bottom: ";
    pushatbottom(s, 6);
    display(s);
    cout << "Reverse stack: ";
    reverse(s);
    display(s);
    cout << "Sort stack: ";
    sortstack(s);
    display(s);

}