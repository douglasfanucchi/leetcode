#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) { // Time: O(n) | Space: O(1)
  int left = 0, right = array.size() - 1, tmp;

  while (left < right) {
    if (array[right] == toMove) {
      right--;
      continue;
    }

    if (array[left] == toMove) {
      tmp = array[right];
      array[right] = array[left];
      array[left] = tmp;
      right--;
    }
    left++;
  }

  return array;
}
