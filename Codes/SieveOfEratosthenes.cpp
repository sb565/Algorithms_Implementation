#include<bits/stdc++.h>
using namespace std;

//Computes all primes <= n
vector<int> sieve(int n) {
    vector<int> isPrime(n + 1, 1), primes;
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = 2*i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    return primes;
}

main() {
    int n = 100;
    for(int i : sieve(n)) {
        cout << i << ' ';
    } cout << '\n';
}
