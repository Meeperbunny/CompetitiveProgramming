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

void TC() {
    ll n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    set<int> els;
    for(auto e : a) els.insert(e);
    vector<int> un(all(els));
    sort(un.begin(), un.end());
    vector<int> d;
    if(un[0] != 1) {
        cout << "Alice" << endl;
        return;
    }
    for(int i = 0; i < un.size() - 1; i++) d.push_back(un[i + 1] - un[i]);
    // Reach a non 1 value, you win
    // Reach the end
    int turn = 0;
    // 0 is alice
    for(int i = 0; i < d.size(); i++) {
        if (d[i] != 1) {
            if (turn == 0) {
                cout << "Bob" << endl;
            }
            if (turn == 1) {
                cout << "Alice" << endl;
            }
            return;
        }
        turn = !turn;
    }
    if (turn == 0) {
        cout << "Alice" << endl;
    }
    if (turn == 1) {
        cout << "Bob" << endl;
    }

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