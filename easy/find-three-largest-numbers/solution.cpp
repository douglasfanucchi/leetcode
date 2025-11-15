#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) { // Time: O(n) | Space: O(1)
  int tmp;

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < array.size() - 1; j++) {
      if (array[j] > array[j + 1]) {
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }

  return {
    array[array.size() - 3],
    array[array.size() - 2],
    array[array.size() - 1],
  };
}
