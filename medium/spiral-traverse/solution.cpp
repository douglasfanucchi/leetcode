#include <vector>

using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array) { // Time: O(n * m) | Space: O(n * m)
  vector<int> result;
  int n = array.size(), m = array[0].size(), start = 0, i, j;

  while ((m - start) > 0 && (n - start) > 0) {
    for(i = start, j = start; i < m; i++) {
      result.push_back(array[j][i]);
    }
    for(i--, j++; j < n; j++) {
      result.push_back(array[j][i]);
    }
    if (i == start || (j - 1) == start) {
      break;
    }
    for(i--, j--; i >= start; i--) {
      result.push_back(array[j][i]);
    }
    for(i++, j--; j > start; j--) {
      result.push_back(array[j][i]);
    }
    start++;
    m--;
    n--;
  }

  return result;
}
