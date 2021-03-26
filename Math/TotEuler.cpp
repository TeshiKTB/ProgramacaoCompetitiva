
// Funcao totiente de euler -> quantidade de numeros coprimos em relacao a n

// Calcula phi de euler na range [1, n] em O(n*logn)
vector<int> range_phi( int n ) {
    bitset<MAX> sieve;
    vector<int> phi(n + 1);
    iota(all(phi), 0);
    sieve.set();

    for ( int p = 2; p <= n; p += 2 ) phi[p] /= 2;

    for ( int p = 3; p <= n; p += 2 ) {
        if ( !sieve[p] ) continue;

        for ( int j = p; j <= n; j += p ) {
            sive[j] = false;
            phi[j] /= p;
            phi[j] *= (p - 1);
        }
    }

    return phi;
}