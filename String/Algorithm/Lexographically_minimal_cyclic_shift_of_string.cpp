//For a given string of len 1e5, we need to
//find the lexographically smallest string
//among all possible cyclic shift of a string.


#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 9;
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;


int power(long long n, long long k, int mod) {
  int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
    pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
  }
  ip1 = power(p1, mod1 - 2, mod1);
  ip2 = power(p2, mod2 - 2, mod2);
  ipw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
    ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
  }
}

pair<int, int> string_hash(string s) {
  int n = s.size();
  pair<int, int> hs({0, 0});
  for (int i = 0; i < n; i++) {
    hs.first += 1LL * s[i] * pw[i].first % mod1;
    hs.first %= mod1;
    hs.second += 1LL * s[i] * pw[i].second % mod2;
    hs.second %= mod2;
  }
  return hs;
}
pair<int, int> pref[N];
void build(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i].first = 1LL * s[i] * pw[i].first % mod1;
    if (i) pref[i].first = (pref[i].first + pref[i - 1].first) % mod1;
    pref[i].second = 1LL * s[i] * pw[i].second % mod2;
    if (i) pref[i].second = (pref[i].second + pref[i - 1].second) % mod2;
  }
}
pair<int, int> get_hash(int i, int j) {
  assert(i <= j);
  pair<int, int> hs({0, 0});
  hs.first = pref[j].first;
  if (i) hs.first = (hs.first - pref[i - 1].first + mod1) % mod1;
  hs.first = 1LL * hs.first * ipw[i].first % mod1;
  hs.second = pref[j].second;
  if (i) hs.second = (hs.second - pref[i - 1].second + mod2) % mod2;
  hs.second = 1LL * hs.second * ipw[i].second % mod2;
  return hs;
}
int lcp(int i, int j, int x, int y) { // O(log n)
  int l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
  while (l <= r) {
    int mid = l + r >> 1;
    if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return ans;
}
/*
0 = equal
-1 = first one is smaller
1 = first one is larger
*/
string s;
int compare(int i, int j, int x, int y) { // O(log n)
  int lc = lcp(i, j, x, y);
  int len1 = j - i + 1, len2 = y - x + 1;
  if (len1 == len2 and lc == len1) return 0; //equal
  else if (lc == len1) return -1;
  else if (lc == len2) return 1;
  else return (s[i + lc] < s[x + lc] ? -1 : 1);
}


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s;
  int n = s.size();
  s += s;
  prec();
  build(s);
  int mni = 0, mnj = n - 1;
  for (int i = 1; i < n; i++) {
    int x = compare(mni, mnj, i, i + n - 1);
    if (x == 1) {
      mni = i, mnj = i + n - 1;
    }
  }
  cout << s.substr(mni, n) << '\n';
  return 0;
}
