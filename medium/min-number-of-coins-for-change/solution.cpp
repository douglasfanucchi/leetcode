#include <vector>
#include <unordered_map>

using namespace std;

int _min(int a, int b) {
    if (a == -1) {
        return b;
    }
    if (b == -1) {
        return a;
    }

    if (a < b) {
        return a;
    }
    return b;
}

int minNumberOfCoinsForChange(int n, vector<int> denoms) {
    if (n == 0) {
        return 0;
    }

    int ans = -1;

    for(int i = 0; i < denoms.size(); i++) {
        if (n - denoms[i] < 0) {
            continue;
        }
        ans = _min(
            ans,
            minNumberOfCoinsForChange(n - denoms[i], denoms) + 1
        );
    }

    return ans;
}
