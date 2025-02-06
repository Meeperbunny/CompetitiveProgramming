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
    int k1, k2;
    cin >> k1;
    vector<int> s1(k1);
    for(auto &e : s1) cin >> e;
    cin >> k2;
    vector<int> s2(k2);
    for(auto &e : s2) cin >> e;

    vector<int> ans1(n, 0), ans2(n, 0);
    vector<int> left1(n, k1), left2(n, k2);
    ans1[0] = -1, left1[0] = 0;
    ans2[0] = -1, left2[0] = 0;
    queue<pair<int, int>> Q; // left to decide, index of
    Q.push({1, 0});
    Q.push({0, 0});
    while(Q.size()) {
        pair<int, int> cr = Q.front();
        Q.pop();
        // cout << cr.first << ' ' << cr.second << endl;
        // for(int i = 0; i < n; i++) cout << left1[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < n; i++) cout << left2[i] << ' ';
        // cout << endl;
        int ind = cr.second;
        if (cr.first) {
            for(auto e : s2) {
                int bind = (ind - e + n) % n;
                // dbg(cr.first, cr.second, bind);
                if (ans1[ind] == -1) {
                    // Make all them wins
                    if (left2[bind] > 0) {
                        left2[bind] = 0;
                        ans2[bind] = 1;
                        Q.push({0, bind});
                    }
                }
                else if (ans1[ind] == 1) {
                    // If is a win, check if all others are wins
                    if (left2[bind] > 0) {
                        left2[bind] -= 1;
                        if (left2[bind] == 0) {
                            ans2[bind] = -1;
                            Q.push({0, bind});
                        }
                    }
                }
            }
        }
        else {
            for(auto e : s1) {
                int bind = (ind - e + n) % n;
                // dbg(cr.first, cr.second, bind);
                if (ans2[ind] == -1) {
                    // Make all them wins
                    if (left1[bind] > 0) {
                        left1[bind] = 0;
                        ans1[bind] = 1;
                        Q.push({1, bind});
                    }
                }
                else if (ans2[ind] == 1) {
                    // If is a win, check if all others are wins
                    if (left1[bind] > 0) {
                        left1[bind] -= 1;
                        if (left1[bind] == 0) {
                            ans1[bind] = -1;
                            Q.push({1, bind});
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i < n; i++) {
        if (ans1[i] == 1) cout << "Win" << ' ';
        if (ans1[i] == 0) cout << "Loop" << ' ';
        if (ans1[i] == -1) cout << "Lose" << ' ';
    }
    cout << endl;
    for(int i = 1; i < n; i++) {
        if (ans2[i] == 1) cout << "Win" << ' ';
        if (ans2[i] == 0) cout << "Loop" << ' ';
        if (ans2[i] == -1) cout << "Lose" << ' ';
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