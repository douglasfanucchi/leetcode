#include <vector>

using namespace std;

int firstDuplicateValue(vector<int> array) { // Time: O(n) | Space: O(n)
    vector<bool> visited;

    for(int i = 0; i < array.size(); i++) {
        visited.push_back(false);
    }

    for(int i = 0; i < array.size(); i++) {
        if (visited[array[i] - 1]) {
            return array[i];
        }
        visited[array[i] - 1] = true;
    }

    return -1;
}
