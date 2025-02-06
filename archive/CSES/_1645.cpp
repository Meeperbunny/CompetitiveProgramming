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

void TC() {
    int n; cin >> n;
    vector<int> a(n);
    multiset<pair<int, int>> pos;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        auto it = pos.insert({a[i], -i - 1});
        it = pos.find({a[i], -i - 1});
        if (it == pos.begin()) {
            cout << 0 << ' ';
        }
        else {
            cout << -prev(it)->second << ' ';
        }
        for(auto t = prev(pos.end()); t != pos.begin();) {
            if (t->second == it->second) break;
            else {
                auto tmp = t;
                t = prev(t);
                pos.erase(tmp);
            }
        }
    }
    cout << endl;
}

int main() {
    HEADER;
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}