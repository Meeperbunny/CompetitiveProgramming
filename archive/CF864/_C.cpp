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
    int n, m;
    cin >> n >> m;
    cout << "? " << 1 << ' ' << 1 << endl;
    cout.flush();
    int m1; cin >> m1;
    cout << "? " << n << ' ' << m << endl;
    cout.flush();
    int m2; cin >> m2;
    int pr = m1 + 1, pc = m1 + 1;
    int prp = n - m2, pcp = m - m2;
    if (pr == prp && pc == pcp) {
        cout << "! " << pr << ' ' << pc << endl;
        cout.flush();
    }
    else if (pr == prp) {
        cout << "? " << pr << ' ' << 1 << endl;
        cout.flush();
        int d; cin >> d;
        cout << "! " << pr << ' ' << d + 1 << endl;
        cout.flush();
    }
    else if (pc == pcp) {
        cout << "? " << 1 << ' ' << pc << endl;
        cout.flush();
        int d; cin >> d;
        cout << "! " << d + 1 << ' ' << pc << endl;
        cout.flush();
    }
    else {
        if (prp < 1 || prp > n || pc < 1 || pc > m) {
            cout << "! " << pr << ' ' << pcp << endl;
            cout.flush();
        }
        else {
            cout << "? " << prp << ' ' << pc << endl;
            cout.flush();
            int d; cin >> d;
            if (d == 0) {
                cout << "! " << prp << ' ' << pc << endl;
                cout.flush();
            }
            else {
                cout << "! " << pr << ' ' << pcp << endl;
                cout.flush();
            }
        }
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