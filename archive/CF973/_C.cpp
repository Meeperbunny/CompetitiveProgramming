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

bool query(const string& s) {
    cout << "? " << s << endl;
    bool res;
    cin >> res;
    return res; // 1 is if substr
}

void ans(const string& s) {
    cout << "! " << s << endl;
    return;
}

void TC() {
    int n; cin >> n;
    if (n == 1) {
        if (query("1")) {
            ans("1");
            return;
        }
        else {
            ans("0");
            return;
        }
    }
    else if (n == 2) {
        if (query("11")) {
            ans("11");
            return;
        }
        if (query("10")) {
            ans("10");
            return;
        }
        if (query("01")) {
            ans("01");
            return;
        }
        if (query("00")) {
            ans("00");
            return;
        }
    }
    else {
        if (query("1")) {
            if (query("10")) {
                // 2 queries made, just brute force
                string curr = "10";
                bool workingonback = false;
                for(int i = 0; i < n - 2; i++) {
                    if (!workingonback) {
                        string checkingZ = curr + "0";
                        string checkingO = curr + "1";
                        if (query(checkingZ)) {
                            curr = checkingZ;
                        }
                        else if (query(checkingO)) {
                            curr = checkingO;
                        }
                        else workingonback = true;
                    }
                    if (workingonback) {
                        string checkingZ = "0" + curr;
                        string checkingO = "1" + curr;
                        if (query(checkingZ)) {
                            curr = checkingZ;
                        }
                        else if (query(checkingO)) {
                            curr = checkingO;
                        }
                    }
                }
                ans(curr);
                return;
            }
            else {
                // is of form 000...000111
                int zs = 0;
                for(int i = 1; i <= n; i++) {
                    if (query(string(i, '0'))) zs = i;
                    else break;
                }
                if (zs) {
                    ans(string(zs, '0') + string(n - zs, '1'));
                    return;
                }
                else {
                    ans(string(n, '1'));
                    return;
                }
            }

        }
        else {
            ans(string(n, '0'));
            return;
        }
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