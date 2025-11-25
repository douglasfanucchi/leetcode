#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) { // Time: O(n^2) | Space: O(n)
	vector<vector<int>> tuples;
	int min;

    if (!array.size()) {
      return -1;
    }

	for(int i = 0; i < array.size() - 1; i++) {
		for(int j = i + 1; j < array.size(); j++) {
			if (array[i] == array[j]) {
				tuples.push_back({i, j});
			}
		}
	}

	if (!tuples.size()) {
		return -1;
	}

	min = tuples[0][1];
	for(int i = 1; i < tuples.size(); i++) {
		if (min > tuples[i][1]) {
			min = tuples[i][1];
		}
	}
	return array[min];
}
