#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);freopen("file.out", "w", stdout);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef pair<ll, ll> p;

bool colinear(p &a, p &b, p &c) {
    ll A = a.first - b.first;
    ll B = a.second - b.second;
    ll C = c.first - b.first;
    ll D = c.second - b.second;
    return A * D == B * C;
}

void TC() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n; cin >> n;
    vector<p> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    shuffle(arr.begin(), arr.end(), rng);

    // Do this 30 times. Choose 2 random indices that are different.
    int maxline = 0;
    for(int i = 0; i < 30; i++) {
        ll a = (rng() + INT_MAX) % n;
        ll b = (rng() + INT_MAX) % n;
        while(a == b) {
            b = (rng() + INT_MAX) % n;
        }
        // Take a and b as the line.
        // If is greater than
        int intheline = 0;
        for(int q = 0; q < n; q++) {
            if (colinear(arr[a], arr[b], arr[q])) intheline++;
        }
        maxline = max(intheline, maxline);
    }
    if (maxline > n / 2) {
        cout << n - maxline << endl;
    }
    else {
        cout << n << endl;
    }
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cout << "Case #" << t + 1 << ": ";
        TC();
    }
    return 0;
}