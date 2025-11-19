#include <vector>

using namespace std;

bool isMonotonic(vector<int> array) { // Time: O(n) | Space: O(1)
  bool nonDecreasing = true, nonIncreasing = true;

  for(int i = 1; i < array.size(); i++) {
    if (array[i] > array[i - 1]) {
      nonIncreasing = false;
    }

    if (array[i] < array[i - 1]) {
      nonDecreasing = false;
    }
  }

  return nonDecreasing || nonIncreasing;
}
