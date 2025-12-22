#include <vector>
using namespace std;

int numberOfWaysToMakeChange(int n, vector<int> denoms) { // Time: O(nm) where m = denoms.size() Space: O(n)
    vector<int> ways;

    for (int i = 0; i <= n; i++) {
        ways.push_back(0);
    }

    ways[0] = 1;

    for(int d: denoms) {
        for(int i = d; i <= n; i++) {
            ways[i] += ways[i - d];
        }
    }

    return ways[n];
}
