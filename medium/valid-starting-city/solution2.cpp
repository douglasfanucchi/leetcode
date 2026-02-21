#include <vector>
using namespace std;

int validStartingCity(vector<int> distances, vector<int> fuel, int mpg) { // Time: O(n) | Space: O(1)
    int miles = 0, ans = 0;

    for(int i = 0; i < distances.size(); i++) {
        miles += (fuel[i] * mpg - distances[i]);

        if (miles < 0) {
            miles = 0;
            ans = i + 1;
        }
    }

    return ans;
}
