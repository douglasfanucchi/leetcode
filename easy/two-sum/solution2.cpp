#include <vector>
#include <map>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) { // Time: O(n) | Space: O(n)
  std::unordered_map<int, bool> map;
  for(int i = 0; i < array.size(); i++) {
    map[array[i]] = true;
  }

  int diff;
  for(int i = 0; i < array.size(); i++) {
    diff = targetSum - array[i];
    if (diff == array[i]) {
      continue;
    }
    if (map.find(diff) != map.end()) {
      return {array[i], diff};
    }
  }
  return {};
}
