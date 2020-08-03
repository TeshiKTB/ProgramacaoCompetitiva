#include <bits/stdc++.h>
using namespace std;

#define ll long long

// SegTree para uma soma no intervalo [l, r];
struct segTree {

    int tam; // tamanho da segTree, deve ser a maior potencia de 2 mais proxima
    vector<ll> s; // vetor com somas

    // init segTree
    segTree( int n ) {
        tam = 1;
        while ( tam < n ) tam <<= 1;

        s = vector<ll>(2 * tam + 1, 0);
    }


    void atualiza( int no, int lx, int rx, int pos, int novo ) {
        if ( lx == rx ) {
            s[no] = novo;
            return;
        }

        int m = (lx + rx) / 2;

        if ( pos <= m ) {
            atualiza(2 * no + 1, lx, m, pos, novo);
        } else {
            atualiza(2 * no + 2, m + 1, rx, pos, novo);
        }
        
        s[no] = s[2 * no + 1] + s[2 * no + 2];
    }


    void atualiza( int i, int nv ) {
        atualiza(0, 0, tam, i, nv);
    }


    ll sum( int no, int l, int r, int lx, int rx ) {
        if ( lx >= l and rx <= r ) {
            return s[no];
        }

        if ( l > rx or r < lx ) {
            return 0;
        }

        int m = (lx + rx) / 2;

        return sum(2 * no + 1, l, r, lx, m) + sum(2 * no + 2, l, r, m + 1, rx);
    }


    ll sum( int l, int r ) {
        return sum(0, l, r - 1, 0, tam);
    }
};


int main () {


    int n, m;
    cin >> n >> m;

    segTree st(n);

    for ( int i = 0; i < n; i++ ) {
        int x;
        cin >> x;
        st.atualiza(i, x);
    }


    for ( int i = 0; i < m; i++ ) {
        int k, l, r;
        cin >> k >> l >> r;

        if ( k == 1 ) {
            st.atualiza(l, r);
        } else {
            cout << st.sum(l, r) << endl;
        }
    }


    return 0;
}