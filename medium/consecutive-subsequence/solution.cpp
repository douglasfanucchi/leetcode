#include <map>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) { // Time: O(nlogn) | Space: O(nlogn)
    map<int, int> dp;
    vector<int> ans;
    int maxN = 0, current;

    if (!arr.size()) {
        return {};
    }

    for(int i = 0; i < arr.size(); i++) {
        dp[arr[i]] = dp[arr[i] - 1] + 1;
        if (dp[arr[i]] > dp[arr[maxN]]) {
            maxN = i;
        }
    }

    current = arr[maxN];
    for(int i = maxN; i >= 0; i--) {
        if (arr[i] == current) {
            ans.push_back(i);
            current--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
