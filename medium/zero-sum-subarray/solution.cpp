#include <vector>
#include <map>

using namespace std;

bool zeroSumSubarray(vector<int> nums) { // Time: O(n) | Space: O(n)
    map<int, bool> map;
    int sum = 0;
    map[0] = true;

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (map.find(sum) != map.end()) {
            return true;
        }
        map[sum] = true;
    }

    return false;
}
