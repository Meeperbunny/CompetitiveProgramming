#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using ll = long long;
int n, m;
ll grid[13][500][500];
ll ntoi[4][500][500][49]; //[nshi]
ll gwt[500][500][49]; //[nshi]
int arr[500][500];
ll ntois[500][500];

const ll MOD = 998244353;

ll add(ll a, ll b) {
    return (a + b) % MOD;
}

ll mul(ll a, ll b) {
    return (a * b) % MOD;
}

vector<pair<int, int>> getadj(int y, int x) {
    vector<pair<int, int>> ret;
    if (x - 1 >= 0) ret.push_back({y, x - 1});
    if (x + 1 < m) ret.push_back({y, x + 1});
    if (y - 1 >= 0) ret.push_back({y - 1, x});
    if (y + 1 < n) ret.push_back({y + 1, x});
    return ret;
}

pair<int, int> ttc(int &t) {
    return {t / 7, t % 7};
}

int ctt(pair<int, int> &t) {
    return t.first * 7 + t.second;
}

int comp_t(int dy, int dx, int old_t) {
    pair<int, int> coord = ttc(old_t);
    coord.first += dy, coord.second += dx;
    return ctt(coord);
}

void TC() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int q = 0; q < m; q++) {
            arr[i][q] = s[q] - 'a';
        }
    }

    vector<pair<string, int>> to_test = {
        {"mpactgenshini", 0}, // 0 is n and i
        {"pactgenshinim", 0}, // 0 is n and i
        {"actgenshinimp", 0}, // 0 is n and i
        {"ctgenshinimpa", 0}, // 0 is n and i
        {"tgenshinimpac", 0}, // 0 is n and i
        {"genshinimpact", 0}, // 0 is n and i
        {"enshinimpactg", 0}, // 0 is n and i
        {"nshinimpactge", 0}, // 0 is n and i
        {"shinimpactgen", 1}, // 1 is just i's
        {"hinimpactgens", 1}, // 1 is just i's
        {"inimpactgensh", 1}, // 1 is just i's
        {"nimpactgenshi", 2}, // 2 is anything
        {"impactgenshin", 3}, // 3 is just n's
    };

    vector<vector<pair<int, int>>> ctomap(26);

    for(int i = 0; i < n; i++) {
        for(int q = 0; q < m; q++) {
            ctomap[arr[i][q]].push_back({i, q});
        }
    }

    // Initalize n to i map
    memset(ntoi, 0, sizeof(ntoi));
    string tst = "nshi";
    for(int i = 0; i < 4; i++) {
        char c = tst[i] - 'a';
        // cout << rot[i] << ' ' << rot[i - 1] << endl;
        for(auto pnt : ctomap[c]) {
            // Check if around are good then add them
            int y = pnt.first, x = pnt.second;
            if (i == 0) ntoi[i][y][x][24] = 1;
            else {
                for(auto adj : getadj(y, x)) {
                    int ay = adj.first, ax = adj.second;
                    for(int old_t = 0; old_t < 49; old_t++) {
                        // Given some adjusted y and adjusted x, compute the new translation
                        int new_t = comp_t(ay - y, ax - x, old_t);
                        if (arr[ay][ax] == tst[i - 1] - 'a') {
                            ntoi[i][y][x][new_t] = add(ntoi[i][y][x][new_t], ntoi[i - 1][ay][ax][old_t]);
                        }
                    }
                }
            }
        }
    }

    // for(int i = 0; i < n; i++) {
    //     for(int q = 0; q < m; q++) {
    //         for(int t = 0; t < 49; t++) {
    //             if (ntoi[3][i][q][t]) {
    //                 cout << i << ' ' << q << ' ' << t << ' ' << ntoi[3][i][q][t] << endl;
    //             }

    //         }
    //     }
    // }

    ll tot = 0;
    for(auto &test : to_test) {
        string& rot = test.first;
        int &type = test.second;
        if (type == 0) {
            // N and I
            "genshinimpact";

            memset(gwt, 0, sizeof(gwt));
            memset(grid, 0, sizeof(grid));
            // Go from left char, end at first i.
            int lasti = 0;
            for(int i = 0; i < 13; i++) {
                lasti = i;
                char c = rot[i] - 'a';
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
                if (rot[i] == 'n') break;
            }


            // cout << rot << endl;
            // for(int i = 0; i < 13; i++) {
            //     for(int q = 0; q < 13; q++) cout << grid[i][0][q] << ' '; cout << endl;
            // }

            for(auto pnt : ctomap['i' - 'a']) {
                // For each i, add all translations to i. note the last translation used. 
                // for each n, look at i's around it. consider all translations. if translation is different, then use
                // a different i.
                int y = pnt.first, x = pnt.second;
                // For each i around me, add the i to n map times value at the coord.
                for(int t = 0; t < 49; t++) {
                    pair<int, int> delta = ttc(t);
                    delta.first -= 3;
                    delta.second -= 3;
                    if (y + delta.first >= 0 && y + delta.first < n) {
                        if (x + delta.second >= 0 && x + delta.second < m) {
                            gwt[y][x][t] = add(gwt[y][x][t], ntoi[3][y][x][t] * grid[lasti][y + delta.first][x + delta.second]);
                        }
                    }
                }
            }



            // cout << rot << endl;
            // cout << "GWT" << endl;
            // for(int i = 0; i < 13; i++) {
            //     cout << gwt[0][i][21] << ' ';
            // } cout << endl;
            // cout << "GWT" << endl;

            // FOR EACH n, find sets of i's around it.
            int nind = lasti + 5;
            for(auto pnt : ctomap['n' - 'a']) {
                // For each n, find all i's around me. Then for all i's around me, look at the i->n map. Add all that are not the one mapping to me.
                int y = pnt.first, x = pnt.second;
                vector<pair<int, int>> around;
                for(auto adj : getadj(y, x)) {
                    int ay = adj.first, ax = adj.second;
                    if (arr[ay][ax] == 'i' - 'a') {
                        around.push_back({ay, ax});
                    }
                }
                for(int i = 0; i < around.size(); i++) {
                    for(int q = 0; q < around.size(); q++) {
                        if (i == q) continue;
                        int ay = around[i].first, ax = around[i].second;
                        int nxy = around[q].first, nxx = around[q].second;
                        for(int t = 0; t < 49; t++) {
                            // For each pair of i's around me, connect gwt: i goes to q if q != i and translation from n != pos_i + delta
                            pair<int, int> delta = ttc(t);
                            delta.first -= 3, delta.second -= 3;
                            // if (gwt[ay][ax][t]) cout << "TRNALSATING AT " << t << ' ' << ay << ' ' << ax << ' ' << nxy << ' ' << nxx << endl;
                            // if (gwt[ay][ax][t]) cout << delta.first + ay << ' ' << delta.second + ax << endl;
                            if (delta.first + ay == y && x == delta.second + ax) {
                            }
                            else {
                                // is good
                                grid[nind][nxy][nxx] = add(grid[nind][nxy][nxx], gwt[ay][ax][t]);
                            }
                        }
                    }
                }
            }




            
            for(int i = nind + 1; i < 13; i++) {
                char c = rot[i] - 'a';
                // cout << rot[i] << ' ' << rot[i - 1] << endl;
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
            }
            // cout << endl;
            // cout << rot << endl;
            // for(int i = 0; i < 13; i++) {
            //     for(int q = 0; q < 13; q++) cout << grid[i][0][q] << ' '; cout << endl;
            //     for(int q = 0; q < 13; q++) cout << grid[i][1][q] << ' '; cout << endl;
            // cout << endl;
            // }

            // Do count like normal
            ll toadd = 0;
            for(auto pnt : ctomap[rot[12] - 'a']) {
                toadd = add(toadd, grid[12][pnt.first][pnt.second]);
            }
            // cout << "Type 0 " << rot << " is adding: " << toadd << endl;
            tot = add(tot, toadd);
        }
        if (type == 1) {
            // Just i's
            memset(grid, 0, sizeof(grid));
            // Go from left char, end at first i.
            int lasti = 0;
            for(int i = 0; i < 13; i++) {
                lasti = i;
                char c = rot[i] - 'a';
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
                if (rot[i] == 'i') break;
            }
            // Have the counts for i, now check for each n that is next to i, add count of i to all other i's around it.
            int myind = lasti + 2;
            for(auto pnt : ctomap['n' - 'a']) {
                // Check if around are good then add them
                int y = pnt.first, x = pnt.second;
                vector<pair<int, int>> around;
                for(auto adj : getadj(y, x)) {
                    int ay = adj.first, ax = adj.second;
                    if (arr[ay][ax] == 'i' - 'a') {
                        around.push_back({ay, ax});
                    }
                }
                // for(auto e : around) cout << e.first << ' ' << e.second << '_'; cout << endl;
                for(int i = 0; i < around.size(); i++) {
                    for(int q = 0; q < around.size(); q++) {
                        if (i != q) {
                            pair<int, int> &c1 = around[i];
                            pair<int, int> &c2 = around[q];
                            grid[myind][c1.first][c1.second] = add(grid[myind][c1.first][c1.second], grid[myind - 2][c2.first][c2.second]);
                        }
                    }
                }
            }

            // Do count like normal
            for(int i = lasti + 3; i < 13; i++) {
                lasti = i;
                char c = rot[i] - 'a';
                // cout << rot[i] << ' ' << rot[i - 1] << endl;
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
            }
            // Do count like normal
            ll toadd = 0;
            for(auto pnt : ctomap[rot[12] - 'a']) {
                toadd = add(toadd, grid[12][pnt.first][pnt.second]);
            }

            // cout << rot << endl;
            // for(int i = 0; i < 13; i++) {
            //     for(int q = 0; q < 13; q++) cout << grid[i][0][q] << ' ';
            //     cout << endl;
            // }
            // cout << "Type 1 " << rot << " is adding: " << toadd << endl;
            tot = add(tot, toadd);

        }
        if (type == 2) {
            // Anything
            memset(grid, 0, sizeof(grid));
            for(int i = 0; i < 13; i++) {
                char c = rot[i] - 'a';
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
            }
            ll toadd = 0;
            for(auto pnt : ctomap[rot[12] - 'a']) {
                toadd = add(toadd, grid[12][pnt.first][pnt.second]);
            }
            // cout << "Type 2 " << rot << " is adding: " << toadd << endl;
            tot = add(tot, toadd);
        }
        if (type == 3) {
            // Just n's, still use the n -> i map
            // impactgenshin
            
            memset(grid, 0, sizeof(grid));
            // Go from left char, end at first i.
            int lasti = 0;
            for(int i = 0; i < 13; i++) {
                lasti = i;
                char c = rot[i] - 'a';
                for(auto pnt : ctomap[c]) {
                    // Check if around are good then add them
                    int y = pnt.first, x = pnt.second;
                    if (i == 0) grid[i][y][x] = 1;
                    else {
                        for(auto adj : getadj(y, x)) {
                            int ay = adj.first, ax = adj.second;
                            if (arr[ay][ax] == rot[i - 1] - 'a') {
                                grid[i][y][x] = add(grid[i][y][x], grid[i - 1][ay][ax]);
                            }
                        }
                    }
                }
                if (rot[i] == 'n') break;
            }
            int myind = lasti + 4;
            for(auto pnt : ctomap['n' - 'a']) {
                // For each n, find all i's around me. Then for all i's around me, look at the i->n map. Add all that are not the one mapping to me.
                int y = pnt.first, x = pnt.second;
                vector<pair<int, int>> around;
                for(auto adj : getadj(y, x)) {
                    int ay = adj.first, ax = adj.second;
                    if (arr[ay][ax] == 'i' - 'a') {
                        around.push_back({ay, ax});
                    }
                }
                // For each i around me, add the i to n map times value at the coord.
                for(int i = 0; i < around.size(); i++) {
                    int ay = around[i].first, ax = around[i].second;
                    for(int t = 0; t < 49; t++) {
                        pair<int, int> delta = ttc(t);
                        delta.first -= 3, delta.second -= 3;
                        if (ay + delta.first == y && ax + delta.second == x) continue;
                        if (ay + delta.first >= 0 && ay + delta.first < n) {
                            if (ax + delta.second >= 0 && ax + delta.second < m) {
                                grid[myind][y][x] = add(grid[myind][y][x], mul(grid[lasti][ay + delta.first][ax + delta.second], ntoi[3][ay][ax][t]));
                            }
                        }
                    }
                }
            }
            

            // cout << rot << endl;
            // for(int i = 0; i < 13; i++) {
            //     for(int q = 0; q < m; q++) cout << grid[i][0][q] << ' '; cout << endl;
            //     cout << endl;
            // }

            ll toadd = 0;
            for(auto pnt : ctomap[rot[12] - 'a']) {
                toadd = add(toadd, grid[12][pnt.first][pnt.second]);
            }
            // cout << "Type 3 " << rot << " is adding: " << toadd << endl;
            tot = add(tot, toadd);
        }
    }

    cout << tot << endl;
}

int main() {
    int T = 1;
    // cin >> T;
    for (int t = 0; t < T; t++) {
        TC();
    }
    return 0;
}