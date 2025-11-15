#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) { // Time: O(n^2) | Space: O(1)
  int max, j, tmp;

  for(int i = 0; i < array.size(); i++) {
    max = 0;
    j = 0;
    for(;j < array.size() - i; j++) {
      if (array[max] < array[j]) {
        max = j;
      }
    }
    tmp = array[j - 1];
    array[j - 1] = array[max];
    array[max] = tmp;
  }

  return array;
}
