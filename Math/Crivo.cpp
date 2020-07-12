#include <bits/stdc++.h>
using namespace std;


const int MAX = 1e5;
bool primos[MAX]; // vetor de primos: true se i eh primo


void crivo() {
  memset(primos, true, sizeof(primos));
  primos[0] = primos[1] = false;
  
  for ( int i = 2; i * i < MAX; i++ ) {

    if ( !primos[i] ) continue; // se nao eh primo, continue
    // se eh primo, todos seus multiplos nao sao primos
    
    for ( int j = i * i; j < MAX; j += i ) primos[j] = false;
  }
}


int main() {
  crivo();
  
  return 0;
}

