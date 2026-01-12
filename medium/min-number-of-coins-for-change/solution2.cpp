#include <vector>

using namespace std;

int _min(int a, int b) {
    if (a == -1) {
        return b;
    }
    if (b == -1) {
        return a;
    }

    if (a < b) {
        return a;
    }

    return b;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) { // Time: O(n * d) | Space: O(n) where d = denoms.size()
    vector<int> dp;

    dp.push_back(0);
    for(int i = 1; i <= n; i++) {
        dp.push_back(-1);
        for(int j = 0; j < denoms.size(); j++) {
            if ((i - denoms[j]) < 0 || dp[i - denoms[j] == -1]) {
                continue;
            }
            dp[i] = _min(1 + dp[i - denoms[j]], dp[i]);
        }
    }

    return dp[n];
}
