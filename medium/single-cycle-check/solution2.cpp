#include <vector>

using namespace std;

bool hasSingleCycle(vector<int> array) {
  int i = 0, j = 0, size = array.size();
  
  while (j < size) {
    if (j && i == 0) {
      return false;
    }
    i = (i + array[i]) % size;
    if (i < 0) {
      i += size;
    }
    j++;
  }

  return i == 0;
}
