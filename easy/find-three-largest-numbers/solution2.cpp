#include <vector>
using namespace std;

void shiftElements(int i, vector<int> &arr) {
  for(int j = 0; j < i; j++) {
    arr[j] = arr[j + 1];
  }
}

vector<int> findThreeLargestNumbers(vector<int> array) { // Time: O(n) | Space: O(1)
  vector<int> result = {INT_MIN, INT_MIN, INT_MIN};

  for(int i = 0; i < array.size(); i++) {
    if (array[i] > result[2]) {
      shiftElements(2, result);
      result[2] = array[i];
    } else if (array[i] > result[1]) {
      shiftElements(1, result);
      result[1] = array[i];
    } else if (array[i] > result[0]) {
      result[0] = array[i];
    }
  }

  return result;
}
