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

double getMinExpectedHorizontalTravelDistance(int N, vector<int> H, vector<int> A, vector<int> B) {
  vector<int> inds(N);
  iota(inds.begin(), inds.end(), 0);
  sort(inds.begin(), inds.end(), [&](int i, int j){return H[i] < H[j];});
  map<int, pair<int, int>> top; // {start, {width, ind}}
  vector<pair<int, int>> fallto(N, {-1, -1});
  for(auto i : inds) {
    // Set the left and right falls.
    int a = A[i], b = B[i];
    auto itL = top.upper_bound(a);
    if (itL != top.begin()) {
      itL = prev(itL);
      // IT IS ON THE LEFT
      if (itL->first + itL->second.first >= a) {
        fallto[i].first = itL->second.second;
      }
    }
    auto itR = top.upper_bound(b);
    if (itR != top.begin()) {
      itR = prev(itR);
      // IT IS ON THE LEFT
      if (itR->first + itR->second.first >= b) {
        fallto[i].second = itR->second.second;
      }
    }
    // Update top with myself.
    auto endIt = (itR == top.end()) ? top.end() : next(itR);
    vector<int> torm;
    vector<pair<int, pair<int, int>>> toCreate;
    for(auto it = itL; it != endIt; it++) {
      int l = it->first;
      int r = l + it->second.first;
      int ind = it->second.second;
      if (l >= b || r <= a) {
        continue;
      }
      else if (l <= a && b <= r) {
        // Create two and remove orig
        torm.push_back(l);
        toCreate.push_back({l, {a - l, ind}});
        toCreate.push_back({b, {r - b, ind}});
      }
      else if (a <= l && r <= b) {
        torm.push_back(l);
      }
      else if (l > a) {
        torm.push_back(l);
        //cout << l << ' ' << r << endl;
        toCreate.push_back({b + 1, {r - b - 1, ind}});
      }
      else {
        torm.push_back(l);
        toCreate.push_back({l, {a - l - 1, ind}});
      }
    }
    if (b - a >= 2) {
      toCreate.push_back({a + 1, {b - a - 2, i}});
    }
    for(auto e : torm) {
      top.erase(e);
    }
    for(auto e : toCreate) {
      top.insert(e);
    }
    // cout << i << endl;
    // for(auto e : top) cout << "{"  << e.first << ' ' << e.second.first << ' ' << e.second.second << "}" << ' ';
    // cout << endl;
  }
  top.clear();
  for(auto i : inds) {
    // Set the left and right falls.
    int a = A[i], b = B[i];
    auto itL = top.lower_bound(a);
    if (itL != top.begin()) {
      itL = prev(itL);
    }
    auto itR = top.upper_bound(b);
    if (itR != top.begin()) {
      itR = prev(itR);
    }
    // Update top with myself.
    auto endIt = (itR == top.end()) ? top.end() : next(itR);
    vector<int> torm;
    vector<pair<int, pair<int, int>>> toCreate;
    for(auto it = itL; it != endIt; it++) {
      int l = it->first;
      int r = l + it->second.first;
      int ind = it->second.second;
      if (l >= b || r <= a) {
        continue;
      }
      else if (l < a && b < r) {
        // Create two and remove orig
        torm.push_back(l);
        toCreate.push_back({l, {a - l, ind}});
        toCreate.push_back({b, {r - b, ind}});
      }
      else if (a <= l && r <= b) {
        torm.push_back(l);
      }
      else if (l > a) {
        torm.push_back(l);
        toCreate.push_back({b, {r - b, ind}});
      }
      else {
        torm.push_back(l);
        toCreate.push_back({l, {a - l, ind}});
      }
    }
    toCreate.push_back({a, {b - a, i}});
    for(auto e : torm) {
      top.erase(e);
    }
    for(auto e : toCreate) {
      top.insert(e);
    }
  }
  vector<vector<pair<double, double>>> topmap(N);
  for(auto e : top) {
    topmap[e.second.second].push_back({e.first, e.second.first});
  }
  //cout << i << endl;
  //for(auto e : top) cout << "{"  << e.first << ' ' << e.second.first << ' ' << e.second.second << "}" << ' ';
  //cout << endl;
  //There is some pleft and dleft (prob of falling of left and distasnce going left, and compliment cleft)
  // Answer is the total etime (from top falls) + the swap (- B + comp - p * LV + p * RV)
  vector<pair<double, double>> fall(N); // Actual contribution to expectation from falling going left or right.
  for(auto i : inds) {
    if (fallto[i].first != -1) {
      fall[i].first += fall[fallto[i].first].first + fall[fallto[i].first].second + B[fallto[i].first] - A[fallto[i].first];
    }
    if (fallto[i].second != -1) {
      fall[i].second += fall[fallto[i].second].first + fall[fallto[i].second].second + B[fallto[i].second] - A[fallto[i].second];
    }
    fall[i].first /= 2.0;
    fall[i].second /= 2.0;
  }
  const double size = 1'000'000.0;
  vector<int> rinds(inds);
  vector<double> ptop(N), pother(N);
  vector<pair<double, double>> topexpect(N), otherexpec(N), sideE(N);
  reverse(rinds.begin(), rinds.end());
  // Now going top to bottom, calculate the expectation contribution of going left/right on a current one, and the prob that we land on one.
  for(auto i : rinds) {
    // Add top to pland and my expectation
    for(auto &[l, r] : topmap[i]) {
      r += l;
      double p = (r - l) / (size) / 2.0;
      ptop[i] += p;
      pother[i] += p;
      double mid = (r + l) / 2.0;
      topexpect[i].first += p * (mid - double(A[i]));
      topexpect[i].second += p * (double(B[i]) - mid);
      
      otherexpec[i].first += p * (mid - double(A[i]));
      otherexpec[i].second += p * (double(B[i]) - mid);
    }
    // propagate my left and right downward. This means add my probs and the expectation of falling.
    
    if (fallto[i].first != -1) {
      int j = fallto[i].first;
      pother[j] += pother[i] / 2;
      
      double mid = A[i];
      otherexpec[j].first += pother[i] * (mid - double(A[j])) / 2;
      otherexpec[j].second += pother[i] * (double(B[j]) - mid) / 2;
    }
    if (fallto[i].second != -1) {
      int j = fallto[i].second;
      pother[j] += pother[i] / 2;
      
      double mid = B[i];
      otherexpec[j].first += pother[i] * (mid - double(A[j])) / 2;
      otherexpec[j].second += pother[i] * (double(B[j]) - mid) / 2;
    }
  }
  double tot = 0;
  for(int i = 0; i < N; i++) {
    // cout << i << ' ' << ptop[i] * (fall[i].first + fall[i].second) + topexpect[i].first + topexpect[i].second << endl;
    tot += ptop[i] * (fall[i].first + fall[i].second) + topexpect[i].first + topexpect[i].second;
  }
  //3*1+1*1.5+4, 3*3+1*2.5+4
  //8.5, 15.5
  cout << tot << endl;
  // for(auto e : otherexpec) cout << e.first << "," << e.second << ' '; cout << endl;
  // for(auto e : fall) cout << e.first << "," << e.second << ' '; cout << endl;
  // for(auto e : ptop) cout << e << ' '; cout << endl;
  // for(auto e : pother) cout << e << ' '; cout << endl;
  double ans = tot;
  for(int i = 0; i < N; i++) {
    double before = pother[i] * (fall[i].first + fall[i].second) + otherexpec[i].first + otherexpec[i].second;
    double afterL = 2.0 * pother[i] * (fall[i].first) + 2.0 * otherexpec[i].first;
    double afterR = 2.0 * pother[i] * (fall[i].second) + 2.0 * otherexpec[i].second;
    double maxSave = before - min(afterL, afterR);
    ans = min(ans, tot - maxSave);
    // cout << i << ' ' << before << ' ' << afterL << ' ' << afterR << ' ' << tot - maxSave << endl;
  }
  return ans;
}


void TC() {
  int N; cin >> N;
  vector<int> H(N), A(N), B(N);
  for(auto &e : H) cin >> e;
  for(auto &e : A) cin >> e;
  for(auto &e : B) cin >> e;
  cout << getMinExpectedHorizontalTravelDistance(N, H, A, B) << endl;
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