
#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) { // Time: O(n^2) | Space: O(1)
  vector<int> result;

  for(int i = 0; i < array.size() - 1; i++) {
    for(int j = i + 1; j < array.size(); j++) {
      if (array[i] + array[j] == targetSum) {
        result.push_back(array[i]);
        result.push_back(array[j]);
        return result;
      }
    }
  }
  return result;
}
