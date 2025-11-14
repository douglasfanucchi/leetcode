#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) { // Time: O(nlogn) | Space: O(1)
  int left = 0, right = array.size() - 1, sum;
  sort(array.begin(), array.end());

  while (left < right) {
    sum = array[left] + array[right];
    if (sum == targetSum) {
      return {array[left], array[right]};
    }
    
    if (sum < targetSum) {
      left++;
    }

    if (sum > targetSum) {
      right--;
    }
  }

  return {};
}
