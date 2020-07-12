#include <bits/stdc++.h>
using namespace std;
 
#define sws ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define fo(i, n) for( int i = 0; i < n; i++ )


bool is_set( int x, int i ) {
    // checa se o bit 'i' do int x está ligado
    return ((x & (1 << i)) != 0);
    // lembrando que (1 << i) == pow(2, i);
}


int lsb( int x ) {
    // least significant bit
    return x & (-x);
}


int count_bits( int x ) {
    // conta quantos bits estão ligados em x
    int cont = 0;
    for( int i = 0; i < 32; i++ ) {
        if ( is_set(x, i) ) {
            cont++;
        }
    }
    return cont;
}


int count_bits2( int x ) {
    // conta quantos bits estão ligados em x utilizando a ideia de lsb
    int cont = 0;
    while ( x != 0 ) {
        cont++;
        x -= lsb(x);
    }
    return cont;
}


bool is_power_of_two( int x ) {
    // verifica se x é uma potência de dois
    if ( x == 0 ) return false;
    return ((x & (x - 1)) == 0);
    // se x for uma potência de dois, terá apenas 1 bit ligado
    // exemplo: se x == 8 (1000), então x - 1 == 7 (0111), portanto, x & (x - 1) == 0
}


void liga( int* x, int i ) {
    // liga o bit i do int x
    *x |= (1 << i);
}


void desliga( int* x, int i )  {
    // desliga o bit i do int x

    // primeiro temos que assegurar que o bit i estará ligado para aplicar o XOR
    liga(x, i);
    // agora, desligamos o bit
    *x ^= (1 << i);
}


int main() {
    
	return 0;
}
