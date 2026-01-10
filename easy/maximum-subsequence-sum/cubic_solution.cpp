#include <vector>

using namespace std;

long solution(vector<int> arr) { // Time: O(n^3) | Space: O(1)
    int ans = 0, total;

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i; j < arr.size(); j++) {
            total = 0;
            for(int k = i; k <= j; k++) {
                total += arr[k];
            }
            if (total > ans) {
                ans = total;
            }
        }
    }

    return ans;
}
