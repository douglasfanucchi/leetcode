#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) { // Time: O(n^2) | Space: O(n)
  vector<vector<int>> result;
  int left, right, sum;

  sort(array.begin(), array.end());

  for(int i = 0; i < array.size(); i++) {
    left = i + 1;
    right = array.size() - 1;

    while (left < right) {
      sum = array[i] + array[left] + array[right];
      if (sum == targetSum) {
        result.push_back({array[i], array[left], array[right]});
        left++;
        right--;
      }

      if (sum < targetSum) {
        left++;
      }

      if (sum > targetSum) {
        right--;
      }
    }
  }

  return result;
}
