#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) { // Time: O(n) | Space: O(n)
  vector<int> ans;
  int product = 1;

  if (!array.size()) {
    return ans;
  }

  for(int i = 0; i < array.size(); i++) {
    if (i != 0) {
      ans.push_back(ans[i - 1] * array[i - 1]);
    } else {
      ans.push_back(1);
    }
  }

  for(int i = array.size() - 1; i >= 0; i--) {
    ans[i] *= product;
    product *= array[i];
  }

  return ans;
}
