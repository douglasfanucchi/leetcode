#include <vector>

using namespace std;

long long maxNum(long long a, long long b) {
    if (a > b) {
        return a;
    }

    return b;
}

long long solution(vector<int> a) { // Time: O(k) | Space: O(k) where k is the biggest element in the vector
    vector<long long> dp, cnt;
    int k = 0;

    for(int n: a) {
        if (n > k) {
            k = n;
        }
    }

    for(int i = 0; i <= k; i++) {
        dp.push_back(0);
        cnt.push_back(0);
    }

    for(int n: a) {
        cnt[n]++;
    }

    dp[0] = 0;
    dp[1] = cnt[1];

    for(int i = 2; i <= k; i++) {
        dp[i] = maxNum(cnt[i] * i + dp[i - 2], dp[i - 1]);
    } 

    return dp[k];
}
