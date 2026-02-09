#include <vector>

using namespace std;

int kadanesAlgorithm(vector<int> array) { // Time: O(n) | Space: O(1)
    if (!array.size()) {
        return 0;
    }

    int ans = array[0], tmp = ans;

    for(int i = 1; i < array.size(); i++) {
        if (tmp < 0) {
            tmp = 0;
        }
        tmp += array[i];
        ans = max(ans, tmp);
    }

    return ans;
}
