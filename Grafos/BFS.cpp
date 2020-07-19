#include <bits/stdc++.h>
using namespace std;

// Algoritmo de busca em grafos
// BFS -> Busca em largura


vector < vector<int> > G;
bool vis[mxN];


void bfs( int x ) {

    queue<int> q;
    int s;
    q.push(x);


    while ( !q.empty() ) {
        s = q.front(); q.pop();

        vis[s] = true;

        for ( auto v : G[s] ) {
            if ( !vis[v] ) q.push(v);
        }
    }
}