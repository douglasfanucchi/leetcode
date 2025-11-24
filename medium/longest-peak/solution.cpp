#include <vector>

using namespace std;

int max(int x, int y) {
  if (x > y) {
    return x;
  }
  return y;
}

int longestPeak(vector<int> array) { // Time: O(n) | Space: O(1)
  int left, right, len = 0;

  if (!array.size()) {
    return len;
  }

  for(int i = 1; i < array.size() - 1; i++) {
    right = i + 1;
    left = i - 1;

    if (array[i] > array[left] && array[i] > array[right]) {
      while (left > 0 && array[left - 1] < array[left]) {
        left--;
      }
      while(right < array.size() - 1 && array[right + 1] < array[right]) {
        right++;
      }
      len = max(len, right - left + 1);
      left = i;
      i = right;
    }
  }

  return len;
}
