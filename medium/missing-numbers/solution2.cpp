#include <vector>

using namespace std;

vector<int> missingNumbers(vector<int> nums) { // Time: O(n) | Space: O(n)
    vector<bool> inArray;
    vector<int> ans;

    for(int i = 0; i < nums.size() + 2; i++) {
        inArray.push_back(false);
    }

    for(int i = 0; i < nums.size(); i++) {
        inArray[nums[i] - 1] = true;
    }

    for(int i = 0; i < inArray.size(); i++) {
        if (!inArray[i]) {
            ans.push_back(i + 1);
        }
    }

    return ans;
}
