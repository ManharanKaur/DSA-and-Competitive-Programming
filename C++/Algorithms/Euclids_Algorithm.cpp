#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    cout << "GCD/ HCF of 20 , 8 is " << gcd(20,8) << endl;
    cout << "LCM of 20 , 8 is " << (20*8) / gcd(20,8) << endl;
    // a*b = hcf(a,b) * lcm(a,b)    =>    lcm(a,b) = (a*b) / hcf(a,b)   
}