#include <vector>
#include <map>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  unordered_map<int, bool> map;
  vector<vector<int>> result;
  int x, y, z;

  sort(array.begin(), array.end());

  for(int i = 0; i < array.size(); i++) {
    map[array[i]] = false;
  }

  for(int i = 0; i < array.size() - 1; i++) {
    y = array[i];
    for(int j = i + 1; j < array.size(); j++) {
      z = array[j];
      x = targetSum - (y + z);
      if (
        map.find(x) != map.end() &&
        !map[z] &&
        z != x &&
        y != x
      ) {
        result.push_back({
          y,
          z,
          x
        });
        map[x] = true;
      }
    }
  }

  return result;
}
