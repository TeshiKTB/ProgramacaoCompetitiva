#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int mxN = 200005;

// Topological Sort
// Eh TOP MESMO

vector< vector<int> > g; // Precisa ser Direcional e Aciclico
bool vis[mxN]; // Para saber se o vertice ja foi visitado
vector<int> ordem; // Vetor com as arestas ordenadas pelo topsort
stack<int> p;


void dfs( int x ) {
    vis[x] = true;

    for ( auto f : g[x] ) if ( !vis[f] ) dfs(f);

    p.push(x);
}


void topsort( int qntv ) {
    while ( !p.empty() ) p.pop();
    memset(vis, false, sizeof(vis));

    for ( int i = 1; i <= qntv; i++  ) {
        if ( !vis[i] ) dfs(i);
    }

    while ( !p.empty() ) {
        ordem.pb(p.top());
        p.pop();
    }
}


int main() {

    int n; // Quantidade de vertices
    int m; // Quantidade de arestas

    cin >> n >> m;

    g = vector< vector<int> >(n + 1);
    for ( int i = 0; i < m; i++ ) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v); // (u -> v) vai da aresta u para a aresta v;
    }

    topsort(n);

    for ( auto vert : ordem ) cout << vert << " ";
    cout << endl;

    return 0;
}
