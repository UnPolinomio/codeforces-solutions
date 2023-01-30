/*
 * Author: UnPolinomio
 * Time: 2023-01-30 02:18:51
**/

#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define deb(x) cout << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
#define fore(x, a, b) for(lli x = a, ___lim___=b; x < ___lim___; ++x)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;
using ii = pair<lli, lli>;

vi primes(lli n) {
  vb p(n + 1, true);
  for(lli i{2}; i * i <= n; ++i) {
    if(!p[i]) continue;
    for(lli j{i * i}; j <= n; j += i) p[j] = false;
  }

  vi ans{};
  fore(i, 2, n + 1) if(p[i]) ans.push_back(i);
  return ans;
}

bool solve(vi& a) {
  static vi ps{ primes(ceil(sqrt(1000000000)))};
  unordered_set<lli> s{};

  for(auto &el : a) {
    for(auto p : ps) {
      if(el % p == 0) {
        if(s.count(p)) return true;
        while(el % p == 0) el /= p;
        s.insert(p);
      }
    }
  }

  for(auto &el : a) {
    if(el == 1) continue;
    if(s.count(el)) return true;
    s.insert(el);
  }

  return false;
}

int main() {
  _;
  lli t{}, n{};
  cin >> t;

  while(t--) {
    cin >> n;
    vi a(n);
    for(auto &el : a) cin >> el;

    puts(solve(a) ? "YES" : "NO");
  }

  return EXIT_SUCCESS;
}
