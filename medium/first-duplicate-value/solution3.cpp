#include <vector>

using namespace std;

int abs(int x) {
  if (x < 0)
      return x * -1;
  return x;
}

int firstDuplicateValue(vector<int> array) { // Time: O(n) | Space: O(1)
    int tmp;

    for(int i = 0; i < array.size(); i++) {
        tmp = abs(array[i]);
		if (array[tmp - 1] < 0) {
			return tmp;
		}
		array[tmp - 1] *= -1;
	}

	return -1;
}
