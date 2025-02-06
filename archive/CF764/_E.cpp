#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(V) V.begin(), V.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m;
    cin >> n >> m;
    vector<string> numbers(n);
    map<string, tuple<int, int, int>> strmap;
    for(int q = 0; q < n; q++) {
        string& e = numbers[q];
        cin >> e;
    }
    string tar; cin >> tar;
    if (m == 1) {
        cout << -1 << endl;
        return;
    }
    bool isG3 = m >= 3;
    for(int q = 0; q < n; q++) {
        string& e = numbers[q];
        for(int i = 0; i < e.size() - 1; i++) {
            strmap[e.substr(i, 2)] = {i + 1, i + 2, q + 1};
        }
        if (isG3) {
            for(int i = 0; i < e.size() - 2; i++) {
                strmap[e.substr(i, 3)] = {i + 1, i + 3, q + 1};
            }
        }
    }
    vector<pair<int, int>> cameFrom(m + 1, {-1, -1});
    cameFrom[0] = {0, 0};
    for(int i = 2; i <= m; i++) {
        // Check 2
        if (i >= 2 && cameFrom[i - 2].first + cameFrom[i - 2].second != -2) {
            string sub2 = tar.substr(i - 2, 2);
            int res = get<2>(strmap[sub2]);
            if (res) {
                cameFrom[i].first = res;
            }
        }
        // Check 3
        if (i >= 3 && cameFrom[i - 3].first + cameFrom[i - 3].second != -2) {
            string sub3 = tar.substr(i - 3, 3);
            int res = get<2>(strmap[sub3]);
            if (res) {
                cameFrom[i].second = res;
            }
        }
    }
    // cout << endl;
    // for(int i = 0; i <= m; i++) {
    //     cout << cameFrom[i].first << ' ' << cameFrom[i].second << endl;
    // }
    // cout << endl;
    if (cameFrom[m].first == -1 && cameFrom[m].second == -1) {
        cout << -1 << endl;
        return;
    }
    int toGoBack = -1;
    int curr = m;
    vector<tuple<int, int, int>> answer;
    while(curr != 0) {
        // Check 2s
        if (cameFrom[curr].first != -1) {
            answer.push_back(strmap[tar.substr(curr - 2, 2)]);
            curr -= 2;
        }
        else if (cameFrom[curr].second != -1) {
            answer.push_back(strmap[tar.substr(curr - 3, 3)]);
            curr -= 3;
        }
        else {
            cout << -1 << endl;
            return;
        }
    }
    reverse(all(answer));
    cout << answer.size() << endl;
    for(int i = 0; i < answer.size(); i++) {
        cout << get<0>(answer[i]) << ' ' << get<1>(answer[i]) << ' ' << get<2>(answer[i]) << endl;
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