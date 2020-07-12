#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

// Fast Exponentiation -> (b ** a ) % mod
ll fexp( ll b, ll a, ll mod = MOD ) {
    ll r = 1;
    b %= mod;

    while ( a > 0 ) {
        if ( a & 1 ) r = (r * b) % mod;
        a >>= 1;
        b = (b * b) % mod;
    }

    return r;
}


int main() {

    cout << fexp(2, 31) << endl;

    return 0;
}