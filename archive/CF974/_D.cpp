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
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> arr;
    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        arr.push_back({max(0, a - d + 1), -1});
        arr.push_back({b, 1});
    }
    sort(all(arr));
    vector<int> inter(n);
    int t = 0;
    int curr = 0;
    for(int i = 0; i < n; i++) {
        assert(curr >= 0);
        // dbg(i, t, arr[t].first);
        while(t != 2 * k && arr[t].first <= i && arr[t].second == -1) {
            // cout << i << ' ' << "Adding" << endl;
            t++;
            curr++;
        }
        inter[i] = curr;

        while(t != 2 * k && arr[t].first <= i && arr[t].second == 1) {
            // cout << i << ' ' << "Rm" << endl;
            t++;
            curr--;
        }
    }
    // cout << "Inter" << endl;
    // for(auto e : inter) cout << e << ' ';
    // cout << endl;
    // multiset<int> s;
    // vector<int> maxes(n);
    // for(int i = 0; i < d; i++) {
    //     // dbg(i);
    //     s.insert(inter[i]);
    // }
    // for(int i = 0; i < n - d + 1; i++) {
    //     // dbg(i);
    //     maxes[i] = *s.rbegin();
    //     s.erase(s.find(inter[i]));
    //     if (i + d < n)
    //         s.insert(inter[i + d]);
    // }
    int ma = -1, maind = -1;
    int mi = INT_MAX, miind = -1;
    // for(int i = 0; i < n; i++) {
    //     cout << maxes[i] << ' ';
    // } cout << endl;
    for(int i = 0; i < n - d + 1; i++) {
        if (inter[i] > ma) {
            maind = i;
            ma = inter[i];
        }
        if (inter[i] < mi) {
            miind = i;
            mi = inter[i];
        }
    }
    cout << maind + 1 << ' ' << miind + 1 << endl;
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