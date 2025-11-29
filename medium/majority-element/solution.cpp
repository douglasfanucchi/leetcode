#include <vector>

using namespace std;

int majorityElement(vector<int> array) { // Time: O(n^2) | Space: O(1)
    int size = array.size(), k;

    for(int i = 0; i < size; i++) {
        k = 0;
        for(int j = 0; j < size; j++) {
            if (array[j] == array[i])
                k++;
        }
        if (k > size / 2) {
            return array[i];
        }
    }

    return -1;
}
