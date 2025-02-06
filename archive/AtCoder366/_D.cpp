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

int a[100][100][100];
int vbar[100][100][100]; // x y z
int rect[101][101][101]; // x y z

void TC() {
    int n; cin >> n;
    memset(a, 0, sizeof(a));
    memset(vbar, 0, sizeof(vbar));
    memset(rect, 0, sizeof(rect));
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < n; q++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][q][j];
            }
        }
    }

    for(int z = 0; z < n; z++) {
        for(int x = 0; x < n; x++) {
            for(int y = n - 1; y >= 0; y--) {
                if (y == n - 1) {
                    vbar[x][y][z] = a[x][y][z];
                }
                else {
                    vbar[x][y][z] = vbar[x][y + 1][z] + a[x][y][z];
                }
            }
        }
    }
    

    for(int z = 0; z < n; z++) {
        for(int y = 0; y < n; y++) {
            for(int x = n - 1; x >= 0; x--) {
                if (x == n - 1) {
                    rect[x][y][z] = vbar[x][y][z];
                }
                else {
                    rect[x][y][z] = rect[x + 1][y][z] + vbar[x][y][z];
                }
            }
        }
    }

    int q; cin >> q;
    while(q--) {
        int x1, x2, y1, y2, z1, z2;
        int tot = 0;
        cin >> x1 >> x2 >> y1 >> y2 >> z1 >> z2;
        x1--, x2--, y1--, y2--, z1--, z2--;
        for(int z = z1; z <= z2; z++) {
            // Get rectangle sum
            tot += rect[x1][y1][z];
            tot -= rect[x1][y2 + 1][z];
            tot -= rect[x2 + 1][y1][z];
            tot += rect[x2 + 1][y2 + 1][z];
        }
        cout << tot << endl;
    }
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