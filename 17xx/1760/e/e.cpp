#include <bits/stdc++.h>
using namespace std;
#define _                           \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0)
using lli = long long int;
using vi = vector<lli>;
using vb = vector<bool>;

lli solve() {
  lli ans{0};
  lli n{};
  cin >> n;

  lli ones{0};
  lli z_onbefore{-1};
  lli z_zeafter{0};
  lli o_onbefore{-1};
  lli o_zeafter{0};
  lli a{};
  while (n--) {
    cin >> a;
    if (a == 1) {
      o_onbefore = ones, o_zeafter = 0;
      ++ones;
    }
    if (a == 0) {
      ++o_zeafter;

      if (z_onbefore == -1)
        z_onbefore = ones;
      else
        ++z_zeafter;
      ans += ones;
    }
  }

  ans = max({ans, z_onbefore != -1 ? ans + z_zeafter - z_onbefore : -1,
             o_onbefore != -1 ? ans + o_onbefore - o_zeafter : -1});

  return ans;
}

int main() {
  _;
  int t{};
  cin >> t;

  while (t--) {
    cout << solve() << '\n';
  }

  return EXIT_SUCCESS;
}