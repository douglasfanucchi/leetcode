#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) { // Time: O(n^2) | Space: O(n)
  vector<int> result;
  int n;

  for(int i = 0; i < array.size(); i++) {
    n = 1;
    for(int j = 0; j < array.size(); j++) {
      if (i != j) {
        n *= array[j];
      }
    }
  }

  return result;
}
