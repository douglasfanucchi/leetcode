#include <vector>

using namespace std;

bool binarySearch(int value, vector<int> arr) {
    int left = 0, right = arr.size() - 1, m;

    while (left < right) {
        m = (left + right) / 2;
        if (value > arr[m]) {
            left = m + 1;
        } else {
            right = m;
        }
    }

    if (arr.size() && arr[left] == value) {
        return true;
    }

    return false;
}

vector<int> missingNumbers(vector<int> nums) { // Time: O(nlogn) | Space: O(n)
    vector<int> ans, aux;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() + 2; i++) {
        aux.push_back(i + 1);
    }

    for(int i = 0; i < aux.size(); i++) {
        if (!binarySearch(aux[i], nums)) {
            ans.push_back(aux[i]);
        }
    }

    return ans;
}
