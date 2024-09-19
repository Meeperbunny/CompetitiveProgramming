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
    char a, b, c;
    // A B C
    // A C B
    // B A C
    // B C A

    // C A B
    // C B A
    cin >> a >> b >> c;
    if (a == '<' && b == '<' && c == '<') cout << "B" << endl;
    if (a == '<' && b == '<' && c == '>') cout << "C" << endl;
    
    if (a == '>' && b == '<' && c == '<') cout << "A" << endl;
    if (a == '>' && b == '>' && c == '<') cout << "C" << endl;
    
    if (a == '<' && b == '>' && c == '>') cout << "A" << endl;
    if (a == '>' && b == '>' && c == '>') cout << "B" << endl;
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