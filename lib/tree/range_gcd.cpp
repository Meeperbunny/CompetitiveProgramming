using ll = long long;
ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    }
    else return gcd(b, a % b);
}

// https://www.geeksforgeeks.org/dsa/sparse-table/
vector<vector<ll>> buildSparseTable(vector<ll> &arr) {
    ll n = arr.size();
    vector<vector<ll>> lookup(n + 1,
                vector<ll>(log2(n) + 1));
    for (ll i = 0; i < n; i++)
        lookup[i][0] = arr[i];
    for (ll j = 1; (1 << j) <= n; j++) {
        for (ll i = 0; (i + (1 << j) - 1) < n; i++) {
            lookup[i][j] = gcd(lookup[i][j - 1], lookup[i + (1 << (j - 1))][j - 1]);
        }
    }

    return lookup;
}

// Returns gcd of [L, R]
ll query(ll L, ll R, vector<vector<ll>> &lookup)  {
    ll j = (ll)log2(R - L + 1);
    return gcd(lookup[L][j], lookup[R - (1 << j) + 1][j]);
}