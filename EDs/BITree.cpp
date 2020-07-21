#include <bits/stdc++.h>
using namespace std;

// Binary Indexed Tree implementation

// Supondo o problema:
// A partir de um vetor 'a', realizar duas operacoes ->
//      1) Fazer a[i] := k, sendo k um valor arbitrario
//      2) Informar a soma de a[l..r] == a[l] + a[l + 1] + ... + a[r]


vector<int> a; // Inicialmente, temos [0, 0, 0, 0, 0, ..., 0]

vector<int> arv; // Vector arv guarda a soma de alguns valores de a
// No caso, guardara a soma dos indices de a[j..k], sendo que
//      j == (k - lsb(k) + 1), lsb == least significant bit;


// Least Significant Bit
int lsb( int x ) {
    return (x & (-x));
}


// Soma no intervalo [0, x] -> a[0..x]
// Em suma, soma(10) = arvore[10] + arvore[8]
// Mas, em binario, soma(110_2) = arvore[110_2] + arvore[100_2]
int soma( int x ) {
    int res = 0;

    while ( x > 0 ) {
        res += arvore[x];
        x -= lsb(x);
    }

    return res;
}


// Para calcular a soma em [l, r], basta soma(r) - soma(l - 1);
int soma_int( int l, int r ) {
    int res = soma(r);
    res -= (l == 0 ? 0 : soma(l - 1));

    return res;
}


// Agora, atualizando os valores na arvore
void atualiza( int i, int novo_valor ) { // a[i] := novo_valor
    int dif = novo_valor - a[i];

    while ( i <= n ) { // Em que 'n' eh a quantidade de elementos de a 
        arvore[i] += dif; // Atualizando soma
        i += lsb(i); // Somando lsb em i. Se i == 10, entao i := 16, ou,
                     // em binario, se i == 110_2, entao i := 1000_2 -> (110_2 + 010_2)
    }
}