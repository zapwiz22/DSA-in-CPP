#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          curr[j] = 1 + prev[j - 1];
        } else {
          curr[j] = max(prev[j], curr[j - 1]);
        }
      }
      prev = curr;
    }
    return n + m - (2 * prev[m]);
  }
};
