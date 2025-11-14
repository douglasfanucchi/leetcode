#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target) { // Time: O(logn) | Space: O(1)
  int left = 0, right = array.size() - 1, m;

  while (left < right) {
    m = (left + right) / 2;
    
    if (target < array[m]) {
      right = m;
    } else {
      left = m + 1;
    }
  }

  if (array[left] == target) {
    return array[left];
  }

  return -1;
}
