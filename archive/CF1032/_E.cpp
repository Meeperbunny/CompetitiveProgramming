#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

ll s[20000];
vector<ll> bd, dd;

set<ll> toTry;

void TC() {
    ll l, r;
    cin >> l >> r;
    bd = vector<ll>(10);
    dd = vector<ll>(10);
    ll tl = l, tr = r;
    for(int i = 0; i < 10; i++) {
        bd[i] = tl % 10;
        tl /= 10;
        dd[i] = tr % 10;
        tr /= 10;
    }
    auto f = [&](ll a, ll b, ll d){
        ll c = 0;
        int i = 0;
        while(a) {
            int dig = a % 10;
            if (dig == bd[i]) c++;
            if (dig == dd[i]) c++;
            a /= 10;
            i++;
        }
        return c;
    };
    ll bst = 3000;
    for(int i = 0; i < 20000; i++) {
        ll num = l + s[i];
        if (num <= r) {
            bst = min(bst, f(num, l, r));
        } else break;
    }
    cout << bst << endl;
}

int main() {
    toTry.insert(0);
    ll m = 1;
    for(int q = 0; q < 9; q++) {
        set<ll> cp(toTry);
        for(auto e : toTry) {
            for(ll v = 0; v < 3; v++) {
                cp.insert(e + v * m);
            }
        }
        swap(cp, toTry);
        m *= 10;
    }
    int i = 0;
    for(auto e : toTry) {
        s[i++] = e;
    }
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}