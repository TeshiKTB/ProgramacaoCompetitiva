#include <bits/stdc++.h>
using namespace std;


// Algoritmo de busca em grafo
// DFS -> Busca em profundidade

vector< vector<int> > G;
bool vis[mxN];


void dfs( int x ) { // x == vertice atual

    vis[x] = true;

    for ( auto v : G[x] ) {
        if ( !vis[v] ) dfs(v);
    }

}