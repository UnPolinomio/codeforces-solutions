/*
 * Author: UnPolinomio
 * Time: 2023-01-29 18:45:52
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

int main() {
  _;
  int t{}, n{}, a{};
  cin >> t;
  while(t--) {
    cin >> n;
    vb taken(n + 1, false);
    int cnt{0};
    fore(i, 0, n) {
      
      cin >> a;
      if(!taken[a]) ++cnt;
      taken[a] = true;
      
    }

    if(cnt >= 3) cout << n << '\n';
    else cout << n / 2 + 1 << '\n';
  }

  return EXIT_SUCCESS;
}
