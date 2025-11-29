#include <vector>

using namespace std;

int majorityElement(vector<int> array) { // Time: O(n) | Space: O(1)
    int ans = -1, x, j, i = 0;

    if (!array.size()) {
        return ans;
    }

    while (i < array.size()) {
        ans = array[i];
        x = 1;
        j = i + 1;

        while (x > 0 && j < array.size()) {
            if (array[j] == array[i]) {
                x++;
            } else {
                x--;
            }
            j++;
        }

        i = j;
    }

    return ans;
}
