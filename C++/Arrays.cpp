#include <iostream>
using namespace std;
int main(){
    // Transversal
    int A[] = {1,2,3,4,5};
    int len  = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < len; i++){
        cout << A[i] << " ";
    }
    cout << endl;

    //__________________________________________
    //Insertion
    int B[7] = {1,2,3,4,5,6,7};
    len  = sizeof(B)/sizeof(B[0]);
    int pos = 5;
    int x = 7;
    for (int i = len-1; i >= pos; i--){
        B[i+1] = B[i]; // shifting elements to right
    }
    B[pos] = x; // inserting elements
    for (int i = 0; i < len; i++){
        cout << B[i] << " ";
    }
    cout << endl;

    //__________________________________________
    //Deletion
    int C[8] = {1,3,6,7,5,4,8,2};
    len  = sizeof(C)/sizeof(C[0]);
    int posi = -1;
    int key = 7;
    for (size_t i = 0; i < len; i++){
        if (C[i] == key){
            posi = i;
            break;
        }
    }
    if ( posi != -1){
        for (int i = posi; i < len; i++){
            C[i] = C[i + 1];
        }
    }
    else
        cout << "Element not Present\n";
    for (int i = 0; i < len - 1; i++){
        cout << C[i] << " ";
    }
    cout << endl;

    //__________________________________________
    //Searching: LINEAR SEARCH
    int D[6] = {16,97,8,4,7,75};
    len  = sizeof(D)/sizeof(D[0]);
    int search_key = 7;
    for (int i = 0; i < len; i++){
        if (D[i] == search_key){
            cout << key << " at " << i << "\n";
        }
        else if (i == len -1 && D[i] == search_key)
            cout << "Element not present\n";
    }

    //__________________________________________
    //Array Reverse using extra array
    int E[6] = {1,2,4,5,6,89};
    len = sizeof(E)/sizeof(E[0]);
    int E_copy[6];
    for (size_t i = 0; i < len; i++){
        E_copy[i] = E[len-1-i];
    }
    for (int i = 0; i < len; i++){
        cout << E_copy[i] << " ";
    }
    cout << endl;

    //__________________________________________
    //Array Reverse using loop in same array
    int F[6] = {1,2,3,4,5,6};
    len = sizeof(F)/sizeof(F[0]);
    int start = 0, end = len - 1, temp;
    while (start < end){
        temp = F[start];
        F[start] = F[end];
        F[end] = temp;
        start++;
        end--;
    }
    for (int i = 0; i < len; i++){
        cout << F[i] << " ";
    }
    cout << endl;
    
    //__________________________________________
    // Rotation of array using temp array (LEFT ROTATION)
    int G[10] = {0,1,2,3,4,5,6,7,8,9};
    int k = 3;
    len = sizeof(G)/sizeof(G[0]);
    int T[len];
    for(int i = 0; i < len; i++){
        T[i] = G[(i + k)%len];
    }
    for(int i = 0; i < len; i++){
        G[i] = T[i];
    }
    for (int i = 0; i < len; i++){
        cout << G[i] << " ";
    }
    cout << endl;

    //__________________________________________
    // Rotation of array using temp array (RIGHT ROTATION)
    int H[10] = {0,1,2,3,4,5,6,7,8,9};// 7 8 9 0 1 2 3 4 5 6
    k = 3;
    len = sizeof(H)/sizeof(H[0]);
    int Tem[len];
    for(int i = 0; i < len; i++){
        Tem[i] = H[(i+ len - k)%len];
    }
    for(int i = 0; i < len; i++){
        H[i] = Tem[i];
    }
    for (int i = 0; i < len; i++){
        cout << H[i] << " ";
    }
    cout << endl;
    
    //__________________________________________
    // Rotation of array one by one(Left rotation)
    int I[10] = {0,1,2,3,4,5,6,7,8,9};
    k = 4;
    len = sizeof(I)/sizeof(I[0]);
    pos = 1;
    int last;
    while (pos <= k){
        last = I[0];
        for (int i = 0; i < len; i++)
            I[i] = I[i + 1]; // Shifting elements to left
        I[len - 1] = last; //Assigh first element to last index
        pos++;
    }
    for (int i = 0; i < len; i++){
        cout << I[i] << " ";
    }
    cout << endl;

    //__________________________________________
    // Rotation of array one by one(Right rotation)
    int J[10] = {0,1,2,3,4,5,6,7,8,9};
    k = 4;
    len = sizeof(J)/sizeof(J[0]);
    pos = 1;
    // int start;
    while (pos <= k){
        start = J[len - 1];
        for (int i = len - 1; i > 0; i--)
            J[i] = J[i - 1]; // Shifting elements to right
        J[0] = start; //Assigh last element to first index
        pos++;
    }
    for (int i = 0; i < len; i++){
        cout << J[i] << " ";
    }
    cout << endl;
}