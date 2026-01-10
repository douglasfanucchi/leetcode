#include <vector>
#include <iostream>

using namespace std;

long solution(vector<int> arr) { // Time: O(n^2) | Space: O(n)
    vector<int> sum;
    int ans = 0, prevSum;

    sum.push_back(arr[0]);

    for(int i = 1; i < arr.size(); i++) {
        sum.push_back(arr[i] + sum[i - 1]);
    }

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            prevSum = 0;
            if (i > 0) {
                prevSum = sum[i - 1];
            }
            if (sum[j] - prevSum > ans) {
                ans = sum[j] - prevSum;
            }
        }
    }

    return ans;
}
