#include <vector>
using namespace std;

int abs(int n) {
  if (n < 0) {
    return n * -1;
  }
  return n;
}

vector<int> sortedSquaredArray(vector<int> array) {
  int smallest = 0;
  int greatest = array.size() - 1;
  int i = array.size() - 1;
  int n;
  vector<int> results(array.size());

  while(smallest <= greatest) {
    n = array[greatest];
    greatest--;
    if (abs(array[smallest]) > abs(n)) {
      n = array[smallest];
      greatest++;
      smallest++;
    }
    results[i] = n*n;
    i--;
  }

  return results;
}
