#include <iostream>
#include <vector>
using namespace std;



// brute force:
// Time complexity : O(n) per number
// If we want array, we need to do it n times 
// Thus making it O(n^2)
bool isprime(int n){
    if (n < 2) return false;
    if (n == 2) return true;
    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


// sieve of eratosthenes:
// Time complexity : O(n log log n)
// Space complexity : O(n)
vector<int> primes(int n){
    vector<int> primes(n+1, true);
    primes[0] = primes[1] = false;

    for(int i = 2; i * i <= n; i++){
        if(primes[i]){
            for(int j = i * i; j <= n; j += i){
                primes[j] = false;
            }
        }
    }
    return primes;
}

int main(){
    int n = 100;
    cout << "Prime numbers up to " << n << " :\n";
    vector<int> prime_numbers = primes(n);

    for(int i = 0; i < n; i++)
        if(prime_numbers[i])
            cout << i << " ";

    return 0;
}