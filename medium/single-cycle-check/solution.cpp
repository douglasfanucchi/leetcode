#include <vector>

using namespace std;

bool hasSingleCycle(vector<int> array) {
  vector<bool> visited;

  int size = array.size();
  
  for(int i = 0; i < size; i++) {
    visited.push_back(false);
  }

  for(int i = 0; i < size; i++) {
    int iterations = 0;
    int j = i;

    for(int k = 0; k < size; k++) {
      visited[k] = false;
    }

    while (iterations < size) {
      if (visited[j]) {
        return false;
      }

      visited[j] = true;
      j = (j + array[j]) % size;
      if (j < 0) {
        j = size + j;
      }
      iterations++;
    }
  }

  return true;
}
