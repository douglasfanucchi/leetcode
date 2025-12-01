#include <vector>

using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) { // Time: O(nlogn) | Space: O(1)
    vector<int> negatives, positives, ans;
    sort(dishes.begin(), dishes.end());

    if (dishes.size() < 2) {
      return {0, 0};
    }

    for(int i = 0; i < dishes.size(); i++) {
      if (dishes[i] < 0) {
        negatives.push_back(dishes[i]);
      } else {
        positives.push_back(dishes[i]);
      }
    }

    if (negatives.size() == 0 || positives.size() == 0) {
      return {0, 0};
    }

    int i = negatives.size() - 1, j = 0;
    ans.push_back(negatives[i]);
    ans.push_back(positives[j]);

    while (i < negatives.size() && j < positives.size()) {
      if (
        ans[0] + ans[1] > target ||
        (
          negatives[i] + positives[j] <= target &&
          negatives[i] + positives[j] > ans[0] + ans[1]
        )
      ) {
        ans[0] = negatives[i];
        ans[1] = positives[j];
      }

      if (negatives[i] + positives[j] > target) {
        i--;
      } else {
        j++;
      }
    }

    if (ans[0] + ans[1] > target) {
      return {0, 0};
    }

    return ans;
}
