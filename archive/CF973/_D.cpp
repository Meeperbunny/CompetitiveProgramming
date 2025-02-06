#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

pair<pair<ll, int>, pair<ll, int>> decomp(ll tot, ll cnt) {
    ll base = tot / cnt;
    ll rem = tot % cnt;
    if (rem == 0) {
        return {{base, cnt},{base - 1, 0}};
    }
    else {
        return {{base + 1, rem},{base, cnt - rem}};
    }
}

void TC() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(auto &e : a) cin >> e;
    map<ll, int> cnts;
    for(int i = n - 1; i >= 0; i--) {
        ll &c = a[i];
        auto it = cnts.begin();
        if (it == cnts.end() || c <= it->first) {
            cnts[c] += 1;
        }
        else if (next(it) == cnts.end()) {
            ll tot = it->second * it->first + c;
            auto res = decomp(tot, it->second + 1);
            cnts.erase(it);
            cnts[res.first.first] += res.first.second;
            if (res.second.second) {
                cnts[res.second.first] += res.second.second;
            }
        }
        else {
            ll nextNum = next(it)->first;
            ll tot = it->second * it->first + c;
            if (tot >= nextNum * (it->second + 1)) {
                tot = tot - nextNum * (it->second);
                cnts[nextNum] += it->second;
                cnts.erase(it);
                c = tot;
                i += 1;
                continue;
            }
            else {
                auto res = decomp(tot, it->second + 1);
                cnts.erase(it);
                cnts[res.first.first] += res.first.second;
                if (res.second.second) {
                    cnts[res.second.first] += res.second.second;
                }
            }
        }
    }
    // cout << "Final Cnts: " << endl;
    // for(auto e : cnts) {
    //     cout << '\t' << e.first << ' ' << e.second << endl;
    // }
    cout << cnts.rbegin()->first - cnts.begin()->first << '\n';
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