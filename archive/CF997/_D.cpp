#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << std::__lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] <= k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    ll tot = 0;
    for(int i = 1; i <= n; i += 2) {
        tot += (n - i + 1); 
    }
    for(int num = 3; num <= 3; num++) {
        vector<pair<int, int>> pre(n + 1);
        for(int i = 1; i <= n; i++) {
            pre[i] = {pre[i - 1].first + int(a[i - 1] < num), pre[i - 1].second + int(a[i - 1] == num)};
        }
        for(int i = 0; i < n; i++) {
            cout << std::format("[{}, {}] ", pre[i].first, pre[i].second); 
        } cout << endl;
        Fenwick<ll> f(n + 1);
        int offset = 0;
        int sz = 0;
        f.add(0, 1);
        for(int i = 1; i < n; i += 2) {
            dbg(i);
            sz += 2;
            offset += 1;
            pair<int, int> pp = pre[i + 1];
            pp.first += offset;
            int needed = sz / 2 + 1;
            cout << "pp is " << pp.first << ' ' << pp.second << endl;
            int x = pp.first + pp.second - needed;
            cout << "Requires " << x << endl;
            if (x + offset >= 0 && pp.second >= 2) {
                cout << "Adding " << f.sum(x + offset) << endl;
                tot += f.sum(x + offset);
            }
            f.add(pp.first + pp.second - offset, 1);
            
            cout << "offset is " << x << endl;
            cout << "Fenwick" << endl;
            for(int q = 0; q < 6; q++) {
                cout << f.rangeSum(q, q + 1) << ' ';
            } cout << endl;
            cout << tot << endl;
        }   
    }


    cout << tot << endl;
}

int main() {
    HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}