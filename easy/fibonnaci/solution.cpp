#include <vector>

int fib(int n) { // Time: O(n) | Space: O(1)
    vector<int> arr;

    int ans;
    arr.push_back(0);
    arr.push_back(1);

    if (n < 2) {
        return arr[n];
    }

    for(int i = 2; i <= n; i++) {
        ans = arr[0] + arr[1];
        arr[0] = arr[1];
        arr[1] = ans;
    }

    return ans;
}