#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

vi ps, tam;


int find_set( int x ) {
    return x == ps[x] ? x : ps[x] = find_set(ps[x]);
}


bool same_set ( int x, int y ) {
    return find_set(x) == find_set(y);
}


void union_set( int x, int y ) {
    int px = find_set(x), py = find_set(y);

    if ( px == py ) return;

    if ( tam[px] < tam[py] ) {
        swap(px, py);
    }

    ps[py] = px;
    tam[px] += tam[py];
}


int main() {

    int n = 10;
    ps = vi(n + 1);
    tam = vi(n + 1, 1);
    iota(ps.begin(), ps.end(), 0); // [0, 1, 2, 3, ...]

    return 0;
}
