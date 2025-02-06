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
    for(int i = 0; i < n; i++) a[i] = i + 1;
    int onf = 0;
    while(a.size() != 1) {
        vector<int> temp;
        for(int i = 1 - onf; i < a.size(); i += 2) {
            cout << a[i] << ' ';
        }
        for(int i = onf; i < a.size(); i += 2) {
            temp.push_back(a[i]);
        }
        onf = (a.size() - onf) % 2 == 1;
        swap(temp, a);
    }
    cout << a[0] << endl;
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