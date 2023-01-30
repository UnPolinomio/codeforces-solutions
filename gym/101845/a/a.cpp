/*
 * Author: UnPolinomio
 * Time: 2023-01-29 22:02:32
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
using Mat = array<array<lli, 4>, 4>;
constexpr lli MOD = 1000000007;

Mat modpow(Mat x, lli k) {
  Mat ans{{
    {1, 0, 0, 0},
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1}
  }};

  while(k > 0) {
    if(k & 1) {
      Mat tmp{};
      fore(i, 0, 4) fore(j, 0, 4) fore(k, 0, 4) {
        tmp[i][j] += (x[i][k] * ans[k][j]) % MOD;
        tmp[i][j] %= MOD;
      }
      ans = tmp;
    }

    Mat tmp{};
    fore(i, 0, 4) fore(j, 0, 4) fore(k, 0, 4) {
      tmp[i][j] += (x[i][k] * x[k][j]) % MOD;
      tmp[i][j] %= MOD;
    }
    x = tmp;
    k >>= 1;
  }

  return ans;
}

lli solve(lli days) {
  if(days < 10) return 1;

  Mat mat {{
    {16, 9, 4, 1},
    {1 , 0, 0, 0},
    {0 , 1, 0, 0},
    {0 , 0, 1, 0}
  }};
  Mat ans = modpow(mat, days / 10 - 1);

  lli res{0};
  fore(i, 0, 3) {
    res += ans[i][0];
    res %= MOD;
  }

  res += 16 * ans[0][0];
  res %= MOD;
  res += 9 * ans[1][0];
  res %= MOD;
  res += 4 * ans[2][0];
  res %= MOD;
  res += ans[3][0];
  res %= MOD;

  if(days % 10 < 5) {
    res += ans[3][0];
    res %= MOD;
  }
  return res;
}

int main() {
  _;

  lli n{};
  cin >> n;
  cout << solve(n) << '\n';

  return EXIT_SUCCESS;
}
