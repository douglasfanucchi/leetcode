#include <map>

using namespace std;

int getNthFib(int n) { // Time: O(n) | Space: O(n)
  static unordered_map<int, int> memo;

  memo[1] = 0;
  memo[2] = 1;

  if (memo.find(n) == memo.end()) {
    memo[n] = getNthFib(n - 1) + getNthFib(n - 2);
  }

  return memo[n];
}
