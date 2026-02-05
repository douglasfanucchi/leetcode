#include <vector>

using namespace std;

int numberOfWaysToTraverseGraph(int width, int height) { // Time: O(width * height) | Space: O(width * height)
    vector<vector<int>> dp;

    for(int i = 0; i < width; i++) {
        dp.push_back({});
        for(int j = 0; j < height; j++) {
            if (i == width - 1 || j == height - 1) {
                dp[i].push_back(1);
            } else {
                dp[i].push_back(0);
            }
        }
    }

    for(int i = width - 2; i >= 0; i--) {
        for(int j = height - 2; j >= 0; j--) {
            dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        }
    }

    return dp[0][0];
}
