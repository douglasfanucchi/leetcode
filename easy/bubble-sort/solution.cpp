#include <vector>
using namespace std;

vector<int> bubbleSort(vector<int> array) { // Time: O(n^2) | Space: O(1)
  int tmp;

  for(int i = 0; i < array.size(); i++) {
    for(int j = 0; j < array.size() - 1 - i; j++) {
      if (array[j] > array[j + 1]) {
        tmp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = tmp;
      }
    }
  }

  return array;
}
