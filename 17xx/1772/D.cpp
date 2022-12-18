#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
#define deb(x) cout << #x << ": " << (x) << '\n';
#define all(x) begin(x), end(x)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;
using ii = pair<lli, lli>;

lli solve(lli n) {
  lli l{}, a{}, mn{0}, mx{1000000000};
  cin >> l;
  while (--n) {
    cin >> a;
    if (a == l) continue;
    lli c{a + l};
    if (a > l)
      mx = min(mx, c / 2);
    else
      mn = max(mn, c % 2 == 0 ? c / 2 : (c + 1) / 2);

    l = a;
  }

  if (mx < mn) return -1;
  return mn;
}

int main() {
  _;
  lli t{}, n{};
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve(n) << '\n';
  }

  return EXIT_SUCCESS;
}
