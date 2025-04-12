#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#endif

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n; cin >> n;
    vector<vector<int>> adj(n);
    int oneIndex = n;
    int zeroIndex = -1;
    vector<int> prospect;
    vector<int> colors(n + 1, -1);
    colors[n] = 1;
    string ans;
    for(int i = n - 1; i >= 1; i--) {
        if (zeroIndex == -1) {
            int oneIsConnected;
            cout << format(" ? {} {}", i, oneIndex) << endl;
            cin >> ans;
            oneIsConnected = (ans == "YES" ? 1 : 0);
            if (oneIsConnected) {
                oneIndex = i;
                colors[i] = 1;
            }
            else {
                zeroIndex = i;
                colors[i] = 0;
            }
        }
        else {
            if (prospect.size() == 0) {
                int oneIsConnected;
                int zeroIsConnected;
                cout << format(" ? {} {}", i, oneIndex) << endl;
                cin >> ans;
                oneIsConnected = (ans == "YES" ? 1 : 0);
                cout << format(" ? {} {}", i, zeroIndex) << endl;
                cin >> ans;
                zeroIsConnected = (ans == "YES" ? 1 : 0);
                // If both, add to prospective.
                if (oneIsConnected && zeroIsConnected) {
                    prospect.push_back(i);
                }
                else if (oneIsConnected) {
                    oneIndex = i;
                    colors[i] = 1;
                }
                else {
                    zeroIndex = i;
                    colors[i] = 0;
                }
            }
            else {
                int prospectIsConnected;
                cout << format(" ? {} {}", i, prospect.back()) << endl;
                cin >> ans;
                prospectIsConnected = (ans == "YES" ? 1 : 0);
                if (prospectIsConnected) {
                    // Add this to prospect
                    prospect.push_back(i);
                }
                else {
                    // Otherwise check if one is
                    int oneIsConnected;
                    cout << format(" ? {} {}", i, oneIndex) << endl;
                    cin >> ans;
                    oneIsConnected = (ans == "YES" ? 1 : 0);
                    if (oneIsConnected) {
                        // Connect one to this, connect 0 to all prospect
                        colors[i] = 1;
                        for(auto e : prospect) {
                            colors[e] = 0;
                        }
                        oneIndex = i;
                        zeroIndex = prospect.back();
                    }
                    else {
                        // Connect one to this, connect 0 to all prospect
                        colors[i] = 0;
                        for(auto e : prospect) {
                            colors[e] = 1;
                        }
                        zeroIndex= i;
                        oneIndex = prospect.back();
                    }
                    prospect.clear();
                }
            }

        }
    }
    for(auto e : prospect) {
        colors[e] = 1;
    }
    cout << "! ";
    for(int i = 1; i <= n; i++) {
        cout << colors[i] << ' ';
    } cout << endl;
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