#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
// using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int query(int a, int b) {
    cout << "? " << a << ' ' << b << endl;
    cout.flush();
    int res; cin >> res;
    return res;
}

void answer(int a) {
    cout << "! " << a << endl;
    cout.flush();
}

void TC() {
    int l = 2, u = 6;
    while(u - l >= 2) {
        int ll = l + (u - l) * 1 / 3;
        int lu = l + (u - l) * 2 / 3;
        int area = query(ll, lu);
        if (area == ll * lu) {
            l = lu + 1;
        }
        else if (area == (ll * (lu + 1))) {
            l = ll + 1;
            u = lu;
        }
        else if (area == ((ll + 1) * (lu + 1))) {
            u = ll;
        }
    }
    if (u == l + 1) {
        int b = l;
        int area = query(b, b);
        if (area == b * b) {
            answer(u);
        }
        else {
            answer(l);
        }
    }
    else {
        answer(l);
    }
}


int main() {
    // HEADER;
    int T = 1;
    cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}