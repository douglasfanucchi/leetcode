#include <vector>
#include <string>

using namespace std;

int _min(int a, int b, int c) {
    if (a < b) {
        if (a < c) {
            return a;
        }

        return c;
    }

    if (b < c) {
        return b;
    }

    return c;
}

int levenshteinDistance(string str1, string str2) { // Time: O(mn) | Space: O(mn) where m = str1.length() and n = str2.length()
    vector<vector<int>> dp;

    for(int i = 0; i <= str1.length(); i++) {
        dp.push_back({});
        for(int j = 0; j <= str2.length(); j++) {
            dp[i].push_back(0);
        }
    }

    for(int i = 1; i <= str1.length(); i++) {
        dp[i][0] = i;
    }

    for(int i = 1; i <= str2.length(); i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i <= str1.length(); i++) {
        for(int j = 1; j <= str2.length(); j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int replace = dp[i - 1][j - 1] + 1;
                int insert = dp[i][j - 1] + 1;
                int _delete = dp[i - 1][j] + 1;

                dp[i][j] = _min(replace, insert, _delete);
            }
        }
    }

    return dp[str1.length()][str2.length()];
}
