#include <vector>

using namespace std;

vector<int> missingNumbers(vector<int> nums) { // Time: O(n) | Space: O(1)
    int total = (nums.size() + 3) * (nums.size() + 2) / 2, numsTotal = 0, diff, avg;

    for(int i = 0; i < nums.size(); i++) {
        numsTotal += nums[i];
    }

    diff = total - numsTotal;
    avg = diff / 2;

    total = (avg + 1) * avg / 2;
    numsTotal = 0;
    for(int i = 0; i < nums.size(); i++) {
        if (nums[i] < avg) {
            numsTotal += nums[i];
        }
    }

    return {total - numsTotal, diff - (total - numsTotal)};
}
