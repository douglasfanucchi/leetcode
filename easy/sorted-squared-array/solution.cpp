#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  vector<int> result;
  int product;

  for(int i = 0; i < array.size(); i++) {
    result.push_back(array[i] * array[i]);
  }

  sort(result.begin(), result.end(), [](int a, int b) {
    return a < b;
  });

  return result;
}
