
// Inversa Modular

// objetivo: (1 / a) mod m

// se m eh primo, pode-se fazer:
ll invMod( ll a, ll m ) {
    return fexp(a, m - 2);
}
