#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

vector<int> getA(vector<int> a) {
    int best = 0;
    map<int, int> cnt;
    vector<int> ret(a.size());
    for(int i = 0; i < a.size(); i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2) best = max(best, a[i]);
        ret[i] = best;
    }
    return ret;
}

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    ll s = 0;
    for(int i = 0; i < n; i++) s += a[i];
    a = getA(a);
    for(int i = 0; i < n; i++) s += a[i];
    a = getA(a);
    for(ll i = n - 1, c = 1; i >= 0; i--, c++) {
        s += c * a[i];
    }
    cout << s << endl;
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