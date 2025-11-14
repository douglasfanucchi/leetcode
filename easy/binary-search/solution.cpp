#include <vector>
using namespace std;
int binarySearchRecursive(vector<int>, int, int, int); 

int binarySearch(vector<int> array, int target) { // Time: O(logn) | Space: O(logn)
  return binarySearchRecursive(array, target, 0, array.size() - 1);
}

int binarySearchRecursive(
  vector<int> array,
  int target,
  int start,
  int end
) {
  int m = (start + end) / 2;

  if (array[m] == target) {
    return m;
  }

  if (start == end) {
    return -1;
  }

  if (target < array[m]) {
    return binarySearchRecursive(array, target, start, m);
  }

  return binarySearchRecursive(array, target, m + 1, end);
}
