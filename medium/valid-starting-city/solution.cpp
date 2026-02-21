#include <vector>

using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) { // Time: O(n^2) | Space: O(1) where n is the number of cities
    int n = distances.size();

    for(int i = 0; i < n; i++) {
        int j, miles = 0;
        for (j = 0; j < n; j++) {
            int currentCity = (i + j) % n;
            miles += mpg * fuel[currentCity];

            if (miles - distances[currentCity] < 0) {
                break;
            }

            miles -= distances[currentCity];
        }

        if (j == n) {
            return i;
        }
    }

    return -1;
}
