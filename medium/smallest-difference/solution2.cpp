#include <vector>
using namespace std;

int abs(int x) {
  if (x < 0) {
    return x * -1;
  }
  return x;
}

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) { // Time: O(nlog(n) + mlog(m)) | Space: O(1)
  int a = 0, b = 0, i = 0, j = 0;

  sort(arrayOne.begin(), arrayOne.end());
  sort(arrayTwo.begin(), arrayTwo.end());  

  while (i < arrayOne.size() && j < arrayTwo.size()) {
    if (abs(arrayOne[i] - arrayTwo[j]) < abs(arrayOne[a] - arrayTwo[b])) {
      a = i;
      b = j;
    }
    if (arrayOne[i] < arrayTwo[j]) {
      i++;
    } else {
      j++;
    }
  }

  while (i < arrayOne.size()) {
    if (abs(arrayOne[i] - arrayTwo[j - 1]) < abs(arrayOne[a] - arrayTwo[b])) {
      a = i;
      b = j - 1;
    }
    i++;
  }
  while (j < arrayTwo.size()) {
    if (abs(arrayOne[i - 1] - arrayTwo[j]) < abs(arrayOne[a] - arrayTwo[b])) {
      a = i - 1;
      b = j;
    }
    j++;
  }

  return {arrayOne[a], arrayTwo[b]};
}
