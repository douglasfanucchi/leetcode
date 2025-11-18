#include <vector>
using namespace std;

int abs(int x) {
  if (x < 0) {
    return x * -1;
  }
  return x;
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) { // Time: O(n * m) | Space: O(1) where n = arrayOne.size() and m = arrayTwo.size()
  int a = 0, b = 0;

  for(int i = 0; i < arrayOne.size(); i++) {
    for(int j = 0; j < arrayTwo.size(); j++) {
      if (abs(arrayTwo[j] - arrayOne[i]) < abs(arrayTwo[b] - arrayOne[a])) {
        a = i;
        b = j;
      }
    }
  }

  return {arrayOne[a], arrayTwo[b]};
}
