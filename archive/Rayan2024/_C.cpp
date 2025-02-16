#include <bits/stdc++.h>
using namespace std;
#define HEADER ios::sync_with_stdio(0);cin.tie(0);if (fopen("file.in", "r")) {freopen("file.in", "r+", stdin);};
#define all(v) v.begin(), v.end()
using ll = long long;
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#ifdef IAN_DEBUG
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void TC() {
    int n, m; cin >> n >> m;
    vector<string> a(n);
    for(auto &e:a) cin >> e;
    vector<vector<bool>> isInfLoop(n, vector<bool>(m));
    vector<vector<bool>> isOut(n, vector<bool>(m));
    vector<vector<int>> color(n, vector<int>(m));
    int c = 1;
    set<pair<int, int>> infloop;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q ++) {
            if (!color[i][q]) {
                vector<pair<int, int>> seen;
                pair<int, int> cv = {i, q};
                bool isl = false;
                c++;
                while(true) {
                    // dbg(cv.first, cv.second);
                    if (cv.first < 0 || cv.first >= n ||
                        cv.second < 0 || cv.second >= m) {
                            
                            for(auto e : seen) {
                                isOut[e.first][e.second] = true;
                            }
                            // none of these do anything. break;
                            break;
                        }
                    if (isOut[cv.first][cv.second]) {
                            seen.push_back(cv);
                            for(auto e : seen) {
                                isOut[e.first][e.second] = true;
                            }
                            // none of these do anything. break;
                            break;

                    }
                    char cc = a[cv.first][cv.second];
                    if (color[cv.first][cv.second] == c) {
                        // Is in a loop.
                        seen.push_back(cv);
                        infloop.insert(all(seen));
                        for(auto e : seen) {
                            isInfLoop[e.first][e.second]= true;
                        }
                        isl = true;
                        break;
                    }
                    color[cv.first][cv.second] = c;
                    if (infloop.count(cv) || cc == '?') {
                        // dbg("QMARK");
                        // Goes to a Qmark.
                        infloop.insert(all(seen));
                        for(auto e : seen) {
                            isInfLoop[e.first][e.second]= true;
                        }
                        isl = true;
                        break;
                    }
                    seen.push_back(cv);
                    // go to next here
                    if (cc == 'U') cv.first -= 1;
                    else if (cc == 'R') cv.second += 1;
                    else if (cc == 'L') cv.second -= 1;
                    else if (cc == 'D') cv.first += 1;
                }
            }
        }
    }
    // If any qmark have an adj qmark or something going into it, then should be inclued.
            vector<pair<int, int>>T = {
                {-1, 0}, {1, 0}, {0, 1}, {0, -1}  
            };
            int wc = 0;
    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            if (a[i][q] == '?') {
                bool works = false;
                // Check if this is good.
                for(auto t : T) {
                    if (i + t.first >= 0 && q + t.second >= 0 &&
                        i + t.first < n && q + t.second < m) {
                            char cc = a[i + t.first][q + t.second];
                            if (t.first == -1 && cc == 'D') works = true;
                            if (t.first == 1 && cc == 'U') works = true;
                            if (t.second == -1 && cc == 'R') works = true;
                            if (t.second == 1 && cc == 'L') works = true;
                            if (cc == '?') works = true;
                            if (isInfLoop[i+t.first][q+t.second]) {
                                works = true;
                            }
                    }
                }
                if (works) wc++;
            }
            else {
                wc += int(isInfLoop[i][q]);
            }
        }
    }
    cout << wc << endl;
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