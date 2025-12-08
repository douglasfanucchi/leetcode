#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> array) { // Time: O(n) | Space: O(1)
    int ans, prev, tmp;

    if (!array.size()) {
        return 0;
    }

    ans = array[0];
    if (array.size() > 1) {
        prev = ans;
        ans = max(array[0], array[1]);
    }

    for(int i = 2; i < array.size(); i++) {
        tmp = ans;
        ans = max(ans, prev + array[i]);
        prev = tmp;
    }

    return ans;
}
