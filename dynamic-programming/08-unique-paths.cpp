#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<vector<ll>> dp(m + 1, vector<ll>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
      }
    }
    return dp[m][n];
  }
};
