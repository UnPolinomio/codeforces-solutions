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

lli solve(vi& p, lli n) {
  lli r{0}, f{0}, s{0};

  for (lli i{1}; i <= n; ++i) {
    lli el{p[i - 1]};
    if (el == i && el == n - i + 1) continue;
    if (el != i && el != n - i + 1)
      ++r;
    else if (el != i)
      ++f;
    else
      ++s;
  }

  if (r == 0) {
    if (s < f) return 2;
    return 1;
  }

  if (f == s) return 0;

  if (s > f) {
    if (s - f >= r) return 1;
    return 0;
  }

  if (s < f) {
    if (f - s > r) return 2;
    return 0;
  }

  return 0;
}

int main() {
  _;
  lli t{}, n{};
  cin >> t;
  while (t--) {
    cin >> n;
    vi p(n);
    for (auto& el : p) cin >> el;
    lli ans{solve(p, n)};

    if (ans == 0)
      cout << "Tie\n";
    else if (ans == 1)
      cout << "First\n";
    else
      cout << "Second\n";
  }

  return EXIT_SUCCESS;
}
