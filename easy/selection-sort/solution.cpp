#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) { // Time: O(n^2) | Space: O(1)
  int min, tmp, j;

  for(int i = 0; i < array.size(); i++) {
    min = j = i;
    for(;j < array.size(); j++) {
      if (array[j] < array[min]) {
        min = j;
      }
    }
    tmp = array[i];
    array[i] = array[min];
    array[min] = tmp;
  }

  return array;
}
