#include <vector>
#include <iostream>

using namespace std;

vector<int> sweetAndSavory(vector<int> dishes, int target) { // Time: O(nlogn) | Space: O(1)
    sort(dishes.begin(), dishes.end());
    vector<int> ans;
    unsigned int left, right;

    if (dishes.size() < 2) {
        return {0, 0};
    }

    left = right = 0;

    while (left < dishes.size() - 1 && dishes[left + 1] < 0) {
        left++;
    }
    while (right < dishes.size() && dishes[right] < 0) {
        right++;
    }

    if (right == dishes.size() || (left == dishes.size() - 1 || dishes[left] > 0)) {
        return {0, 0};
    }

    ans.push_back(dishes[left]);
    ans.push_back(dishes[right]);

    while (left < dishes.size() && right < dishes.size()) {
        if (
            dishes[left] + dishes[right] <= target
            && (
              ans[0] + ans[1] > target ||
              dishes[left] + dishes[right] > ans[0] + ans[1]
            )
        ) {
            ans[0] = dishes[left];
            ans[1] = dishes[right];
        }

        if (dishes[left] + dishes[right] <= target) {
            right++;
        } else {
            left--;
        }
    }

    if (ans[0] + ans[1] > target) {
      return {0, 0};
    }

    return ans;
}
