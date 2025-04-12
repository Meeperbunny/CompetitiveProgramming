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


const int N = 5000000;
ll primes[N / 5 + 1];
bool isnotprime[N + 1];
int pc = 0;
void sieve() {
    memset(isnotprime, 0, sizeof(isnotprime));
    isnotprime[0] = 1;
    isnotprime[1] = 1;
    for(int i = 2; i <= N; i++) {
        if (!isnotprime[i]) {
            primes[pc++] = i;
            for(int q = i * 2; q <= N; q += i) {
                isnotprime[q] = 1;
            }
        }
    }
}

void TC() {
    int n; cin >> n;
    vector<int> order;
    set<int> left;
    for(int i = 1; i <= n; i++) {
        left.insert(i);
    }
    if (n < 50) {
        order = vector<int>(n);
        order[0] = 2;
        order[1] = 1;
        for(int i = 2; i < n; i++) {
            order[i] = i + 1;
        }
    }
    else {
        int mid = n / 2;
        for(int q = mid;; q++) {
            if (!isnotprime[q]) {
                mid = q;
                break;
            }
        }
        int i = 0;
        while(left.size()) {
            auto it = left.lower_bound(mid);
            i++;
            if (i & 1) {
                if (it == left.end()) continue;
                order.push_back(*it);
            }
            else {
                if (it == left.begin()) continue;
                it = prev(it);
                order.push_back(*it);
            }
            left.erase(it);
        }
    }
    for(auto e : order) cout << e << ' ';
    cout << endl;
}

int main() {
    sieve();
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}